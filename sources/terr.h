//#include <windows.h>
#ifndef TERR_H_
#define TERR_H_

#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "imageloader.h"
#include "vec3f.h"
//#include "b.h"

using namespace std;

class Terrain {
	/** Represents a terrain, by storing a set of heights and normals at 2D locations */

private:
	int w; //Width
	int l; //Length
	float** hs; //Heights
	Vec3f** normals;
	bool computedNormals; //Whether normals is up-to-date
public:
	Terrain(int w2, int l2);
	~Terrain();
	int width();
	int length();
	void setHeight(int x, int z, float y);
	float getHeight(int x, int z);
	void computeNormals(); //Smooth out the normals
	Vec3f getNormal(int x, int z);
};

Terrain* loadTerrain(const char* filename, float height);

GLuint loadTexture(Image* image);

void initTerrain(const char* filename1, const char* filename2);
void drawTerrain();
int getMyTerrainHeight(int xx, int zz);
Vec3f getMyTerrainNormal(int xx, int zz);
void call();
void cleanup();
void initRendering();
int fun(int x);
#endif
