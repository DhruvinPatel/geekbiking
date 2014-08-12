/*
 * render.cpp
 *
 *  Created on: 03-Sep-2013
 *      Author: rohit
 */

#ifdef _WIN32
#include <windows.h>
#endif
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
#include <sstream>
#include "render.h"
#include "hud.h"
#include <math.h>

#define PI 3.141592655
using namespace std;


GLuint textureId;
GLuint textureId1;
GLuint textureId2;
void initObstacle() {
	/** initObstacle: Loads all obstacles.obj files in memory */
	Image* image1 = loadBMP("objects/can.bmp");
	textureId = loadTexture2(image1);
	delete image1;
	Image* image2 = loadBMP("objects/hell_pig.bmp");
	textureId1 = loadTexture2(image2);
	delete image2;
	Image* image3 = loadBMP("objects/wood.bmp");
		textureId2 = loadTexture2(image2);
		delete image3;

}

GLuint loadTexture2(Image* image) {
	/** loadTexture2: Loads the texture for terrain in memory */
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0,
			GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}
void renderObject(GLMmodel *myModel) {
	/** renderObject: Renders the object file of bike and player with color */
//	glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, textureId1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glmFacetNormals(myModel);
	glmVertexNormals(myModel, 1000);
	glmDraw(myModel,GLM_TEXTURE | GLM_MATERIAL | GLM_SMOOTH);
//	glDisable(GL_TEXTURE_2D);


}

void renderObstacle(GLMmodel *myModel,int i)
{
	/** renderObstacle: render the obstacles according to track number given */
	//glScalef(0.1,0.1,0.1);
	glColor3f(1.0,1.0,1.0);
	glEnable(GL_TEXTURE_2D);
		if(i ==0)
		{
		glBindTexture(GL_TEXTURE_2D, textureId);
		}
		else {
			glTranslatef(1,0,0);
			glScalef(2.5, 2.5, 2.5);
			glBindTexture(GL_TEXTURE_2D,textureId2);
		}
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glmFacetNormals(myModel);
		glmVertexNormals(myModel, 1000);
		glmDraw(myModel, GLM_TEXTURE | GLM_MATERIAL | GLM_SMOOTH);
		glDisable(GL_TEXTURE_2D);

}

