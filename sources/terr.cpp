//#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "imageloader.h"
#include "vec3f.h"
#include "terr.h"
float angle_ = 0.0f;
float x_ = 100.0f;
float z_ = 100.0f;
float y_ = 0.0f;
//#include "b.h"

GLuint _textureId1;
GLuint _textureId2;
Terrain* _terrain;
float frustum[6][4];
using namespace std;

Terrain::Terrain(int w2, int l2) {
	/** Represents a terrain, by storing a set of heights and normals at 2D locations */
	w = w2;
	l = l2;

	hs = new float*[l];
	for (int i = 0; i < l; i++) {
		hs[i] = new float[w];
	}

	normals = new Vec3f*[l];
	for (int i = 0; i < l; i++) {
		normals[i] = new Vec3f[w];
	}

	computedNormals = false;
}

Terrain::~Terrain() {
	for (int i = 0; i < l; i++) {
		delete[] hs[i];
	}
	delete[] hs;

	for (int i = 0; i < l; i++) {
		delete[] normals[i];
	}
	delete[] normals;
}

int Terrain::width() {
	return w;
}

int Terrain::length() {
	return l;
}

//Sets the height at (x, z) to y
void Terrain::setHeight(int x, int z, float y) {
	hs[z][x] = y;
	computedNormals = false;
}

//Returns the height at (x, z)
float Terrain::getHeight(int x, int z) {
	return hs[z][x];
}

void ExtractFrustum() {
	float proj[16];
	float modl[16];
	float clip[16];
	float t;

	/* Get the current PROJECTION matrix from OpenGL */
	glGetFloatv(GL_PROJECTION_MATRIX, proj);

	/* Get the current MODELVIEW matrix from OpenGL */
	glGetFloatv(GL_MODELVIEW_MATRIX, modl);

	/* Combine the two matrices (multiply projection by modelview) */
	clip[0] = modl[0] * proj[0] + modl[1] * proj[4] + modl[2] * proj[8]
			+ modl[3] * proj[12];
	clip[1] = modl[0] * proj[1] + modl[1] * proj[5] + modl[2] * proj[9]
			+ modl[3] * proj[13];
	clip[2] = modl[0] * proj[2] + modl[1] * proj[6] + modl[2] * proj[10]
			+ modl[3] * proj[14];
	clip[3] = modl[0] * proj[3] + modl[1] * proj[7] + modl[2] * proj[11]
			+ modl[3] * proj[15];

	clip[4] = modl[4] * proj[0] + modl[5] * proj[4] + modl[6] * proj[8]
			+ modl[7] * proj[12];
	clip[5] = modl[4] * proj[1] + modl[5] * proj[5] + modl[6] * proj[9]
			+ modl[7] * proj[13];
	clip[6] = modl[4] * proj[2] + modl[5] * proj[6] + modl[6] * proj[10]
			+ modl[7] * proj[14];
	clip[7] = modl[4] * proj[3] + modl[5] * proj[7] + modl[6] * proj[11]
			+ modl[7] * proj[15];

	clip[8] = modl[8] * proj[0] + modl[9] * proj[4] + modl[10] * proj[8]
			+ modl[11] * proj[12];
	clip[9] = modl[8] * proj[1] + modl[9] * proj[5] + modl[10] * proj[9]
			+ modl[11] * proj[13];
	clip[10] = modl[8] * proj[2] + modl[9] * proj[6] + modl[10] * proj[10]
			+ modl[11] * proj[14];
	clip[11] = modl[8] * proj[3] + modl[9] * proj[7] + modl[10] * proj[11]
			+ modl[11] * proj[15];

	clip[12] = modl[12] * proj[0] + modl[13] * proj[4] + modl[14] * proj[8]
			+ modl[15] * proj[12];
	clip[13] = modl[12] * proj[1] + modl[13] * proj[5] + modl[14] * proj[9]
			+ modl[15] * proj[13];
	clip[14] = modl[12] * proj[2] + modl[13] * proj[6] + modl[14] * proj[10]
			+ modl[15] * proj[14];
	clip[15] = modl[12] * proj[3] + modl[13] * proj[7] + modl[14] * proj[11]
			+ modl[15] * proj[15];

	/* Extract the numbers for the RIGHT plane */
	frustum[0][0] = clip[3] - clip[0];
	frustum[0][1] = clip[7] - clip[4];
	frustum[0][2] = clip[11] - clip[8];
	frustum[0][3] = clip[15] - clip[12];

	/* Normalize the result */
	t = sqrt(
			frustum[0][0] * frustum[0][0] + frustum[0][1] * frustum[0][1]
					+ frustum[0][2] * frustum[0][2]);
	frustum[0][0] /= t;
	frustum[0][1] /= t;
	frustum[0][2] /= t;
	frustum[0][3] /= t;

	/* Extract the numbers for the LEFT plane */
	frustum[1][0] = clip[3] + clip[0];
	frustum[1][1] = clip[7] + clip[4];
	frustum[1][2] = clip[11] + clip[8];
	frustum[1][3] = clip[15] + clip[12];

	/* Normalize the result */
	t = sqrt(
			frustum[1][0] * frustum[1][0] + frustum[1][1] * frustum[1][1]
					+ frustum[1][2] * frustum[1][2]);
	frustum[1][0] /= t;
	frustum[1][1] /= t;
	frustum[1][2] /= t;
	frustum[1][3] /= t;

	/* Extract the BOTTOM plane */
	frustum[2][0] = clip[3] + clip[1];
	frustum[2][1] = clip[7] + clip[5];
	frustum[2][2] = clip[11] + clip[9];
	frustum[2][3] = clip[15] + clip[13];

	/* Normalize the result */
	t = sqrt(
			frustum[2][0] * frustum[2][0] + frustum[2][1] * frustum[2][1]
					+ frustum[2][2] * frustum[2][2]);
	frustum[2][0] /= t;
	frustum[2][1] /= t;
	frustum[2][2] /= t;
	frustum[2][3] /= t;

	/* Extract the TOP plane */
	frustum[3][0] = clip[3] - clip[1];
	frustum[3][1] = clip[7] - clip[5];
	frustum[3][2] = clip[11] - clip[9];
	frustum[3][3] = clip[15] - clip[13];

	/* Normalize the result */
	t = sqrt(
			frustum[3][0] * frustum[3][0] + frustum[3][1] * frustum[3][1]
					+ frustum[3][2] * frustum[3][2]);
	frustum[3][0] /= t;
	frustum[3][1] /= t;
	frustum[3][2] /= t;
	frustum[3][3] /= t;

	/* Extract the FAR plane */
	frustum[4][0] = clip[3] - clip[2];
	frustum[4][1] = clip[7] - clip[6];
	frustum[4][2] = clip[11] - clip[10];
	frustum[4][3] = clip[15] - clip[14];

	/* Normalize the result */
	t = sqrt(
			frustum[4][0] * frustum[4][0] + frustum[4][1] * frustum[4][1]
					+ frustum[4][2] * frustum[4][2]);
	frustum[4][0] /= t;
	frustum[4][1] /= t;
	frustum[4][2] /= t;
	frustum[4][3] /= t;

	/* Extract the NEAR plane */
	frustum[5][0] = clip[3] + clip[2];
	frustum[5][1] = clip[7] + clip[6];
	frustum[5][2] = clip[11] + clip[10];
	frustum[5][3] = clip[15] + clip[14];

	/* Normalize the result */
	t = sqrt(
			frustum[5][0] * frustum[5][0] + frustum[5][1] * frustum[5][1]
					+ frustum[5][2] * frustum[5][2]);
	frustum[5][0] /= t;
	frustum[5][1] /= t;
	frustum[5][2] /= t;
	frustum[5][3] /= t;
}

bool PointInFrustum(float x, float y, float z) {
	int p;

	for (p = 0; p < 6; p++)
		if (frustum[p][0] * x + frustum[p][1] * y + frustum[p][2] * z
				+ frustum[p][3] <= -10)
			return false;
	return true;
}

//Computes the normals, if they haven't been computed yet
void Terrain::computeNormals() {
	if (computedNormals) {
		return;
	}

	//Compute the rough version of the normals
	Vec3f** normals2 = new Vec3f*[l];
	for (int i = 0; i < l; i++) {
		normals2[i] = new Vec3f[w];
	}

	for (int z = 0; z < l; z++) {
		for (int x = 0; x < w; x++) {
			Vec3f sum(0.0f, 0.0f, 0.0f);

			Vec3f out;
			if (z > 0) {
				out = Vec3f(0.0f, hs[z - 1][x] - hs[z][x], -1.0f);
			}
			Vec3f in;
			if (z < l - 1) {
				in = Vec3f(0.0f, hs[z + 1][x] - hs[z][x], 1.0f);
			}
			Vec3f left;
			if (x > 0) {
				left = Vec3f(-1.0f, hs[z][x - 1] - hs[z][x], 0.0f);
			}
			Vec3f right;
			if (x < w - 1) {
				right = Vec3f(1.0f, hs[z][x + 1] - hs[z][x], 0.0f);
			}

			if (x > 0 && z > 0) {
				sum += out.cross(left).normalize();
			}
			if (x > 0 && z < l - 1) {
				sum += left.cross(in).normalize();
			}
			if (x < w - 1 && z < l - 1) {
				sum += in.cross(right).normalize();
			}
			if (x < w - 1 && z > 0) {
				sum += right.cross(out).normalize();
			}

			normals2[z][x] = sum;
		}
	}

	//Smooth out the normals
	const float FALLOUT_RATIO = 0.5f;
	for (int z = 0; z < l; z++) {
		for (int x = 0; x < w; x++) {
			Vec3f sum = normals2[z][x];

			if (x > 0) {
				sum += normals2[z][x - 1] * FALLOUT_RATIO;
			}
			if (x < w - 1) {
				sum += normals2[z][x + 1] * FALLOUT_RATIO;
			}
			if (z > 0) {
				sum += normals2[z - 1][x] * FALLOUT_RATIO;
			}
			if (z < l - 1) {
				sum += normals2[z + 1][x] * FALLOUT_RATIO;
			}

			if (sum.magnitude() == 0) {
				sum = Vec3f(0.0f, 1.0f, 0.0f);
			}
			normals[z][x] = sum;
		}
	}

	for (int i = 0; i < l; i++) {
		delete[] normals2[i];
	}
	delete[] normals2;

	computedNormals = true;
}

//Returns the normal at (x, z)
Vec3f Terrain::getNormal(int x, int z) {
	if (!computedNormals) {
		computeNormals();
	}
	return normals[z][x];
}

Terrain* loadTerrain(const char* filename, float height) {
	/** Loads a terrain from a heightmap.  The heights of the terrain range from
	 * -height / 2 to height / 2. */
	Image* image = loadBMP(filename);
	Terrain* t = new Terrain(image->width, image->height);
	for (int y = 0; y < image->height; y++) {
		for (int x = 0; x < image->width; x++) {
			unsigned char color = (unsigned char) image->pixels[3
					* (y * image->width + x)];
			float h = height * ((color / 255.0f) - 0.5f);
			t->setHeight(x, y, h);

		}
	}

	delete image;
	t->computeNormals();
	return t;
}

void initTerrain(const char* filename1, const char* filename2) {
	/** initTerrain : loads the terrain into memory */
	Image* image1 = loadBMP(filename2);
	_textureId1 = loadTexture(image1);
	delete image1;
	Image* image2 = loadBMP("objects/hell_pig.bmp");
	_textureId2 = loadTexture(image2);
	delete image2;
	_terrain = loadTerrain(filename1, 60);
}

GLuint loadTexture(Image* image) {
	/** loadTexture: loads the texture into the memory and binds it with
	 * terrain
	 */
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0,
			GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

float bb = 2.0;

int getMyTerrainHeight(int xx, int zz) {
	/** getMyTerrainNormal: returns the y coordinate of terrain at given x and z
	 * coordinates
	 */
	int yy;
	yy = _terrain->getHeight(fun(xx), fun(zz));
	return yy;
}

Vec3f getMyTerrainNormal(int xx, int zz) {
	/** getMyTerrainNormal: returns the normal vector at given x and z
	 * coordinates
	 */
	Vec3f a = _terrain->getNormal(fun(xx), fun(zz)).normalize();
	return a;
}

void drawTerrain() {
	/** drawTerrain: draws the terrain that is loaded into memory
	 * using frustum culling.
	 */
	glPushMatrix();

	GLfloat ambientColor[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor0[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat lightPos0[] = { 0.0f, 0.8f, 0.1f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTranslatef(-(float) (_terrain->width()) / 2, 0.0f,
			-(float) (_terrain->length()) / 2);

	glColor3f(1.0f, 1.0f, 1.0f);
	ExtractFrustum();
	for (int z = 0; z < _terrain->length() - 1; z++) {
		//Makes OpenGL draw a triangle at every three consecutive vertices
		glBegin(GL_TRIANGLE_STRIP);
		for (int x = 0; x < _terrain->width(); x += 2) {
			if (PointInFrustum(x, _terrain->getHeight(x, z), z)) {
				Vec3f normal = _terrain->getNormal(x, z);
				glNormal3f(normal[0], normal[1], normal[2]);
				glTexCoord2f((float) x / _terrain->width(),
						(float) z / _terrain->length());
				glVertex3f(x, _terrain->getHeight(x, z), z);
				normal = _terrain->getNormal(x, z + 1);
				glNormal3f(normal[0], normal[1], normal[2]);
				glTexCoord2f((float) x / _terrain->width(),
						(float) (z + 1) / _terrain->length());
				glVertex3f(x, _terrain->getHeight(x, z + 1), z + 1);
				glNormal3f(normal[0], normal[1], normal[2]);
				glTexCoord2f((float) (x + 1) / _terrain->width(),
						(float) z / _terrain->length());
				glVertex3f(x + 1, _terrain->getHeight(x + 1, z), z);
				glNormal3f(normal[0], normal[1], normal[2]);
				glTexCoord2f((float) (x + 1) / _terrain->width(),
						(float) (z + 1) / _terrain->length());
				glVertex3f(x + 1, _terrain->getHeight(x + 1, z + 1), z + 1);
			}
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

int fun(int x) {
	return x + 512;
}
void cleanup() {
	delete _terrain;
}
