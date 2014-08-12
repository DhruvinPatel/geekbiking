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
#include "terr.h"
#include <sstream>
#include "hud.h"
#include <math.h>

#define PI 3.141592655
using namespace std;

float circleangle = 0;
GLuint _textureId3;

void initBackGround(const char* filename) {

	Image* image3 = loadBMP(filename);
	_textureId3 = loadTexture1(image3);
	delete image3;
}

GLuint loadTexture1(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0,
			GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void print(string Text,const float x,const float y,const float z)
{
	glRasterPos3f(x,y,z);
	for (int i = 0; i < Text.length(); i++) {
			glColor3f(0.0, 0.0, 1.0);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Text[i]);
		}
}

void printtext2d(const float x, const float y, const float z, int a, int b) {

	glColor3f(0.0, 0.0, 0.0);
	string Text = "GEEK BIKING";
	print("SPEED",x-7.2,y+3.5,z);
	print("TIMER - ",x+25,y+3.5,z);
	print("SCORES - ",x+25,y+2,z);
	stringstream ss;
	ss << a;
	string str = ss.str();
	print(str,x+30,y+3.5,z);
	stringstream tt;
	tt << b;
	string ttr = tt.str();
	print(ttr,x+30,y+2,z);
	if(a==5)
	{
		print("5   SECONDS   LEFT !!!!!",x+10,y+1.5,z);
	}
	if(a==4)
		{
			print("4   SECONDS   LEFT !!!!!",x+10,y+1.5,z);
		}
	if(a==3)
		{
			print("3   SECONDS   LEFT !!!!!",x+10,y+1.5,z);
		}
	if(a==2)
		{
			print("2   SECONDS   LEFT !!!!!",x+10,y+1.5,z);
		}
	if(a==1)
		{
			print("1   SECOND   LEFT !!!!!",x+10,y+1.5,z);
		}

}

void drawHUD(float x, float y, float z, float angle, int a, int b,
		float cvelocity) {
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glTranslatef(x, y, z);
	glPushMatrix();
	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);

	glTexCoord2d(1, 0.0);
	glVertex2f(17.6, 10.2);
	glTexCoord2d(0, 0.0);
	glVertex2f(-17.6, 10.2);
	glTexCoord2d(0, 1.0);
	glVertex2f(-17.6, 14.05);
	glTexCoord2d(1, 1);
	glVertex2f(17.6, 14.05);

	glEnd();

	glColor3f(0, 0, 0);
	printtext2d(-15, 11.8, -10, a, b);
	glPopMatrix();
	glRotatef(angle, 0, 1, 0);
	glTranslatef(-13, 13, -10);
	glScalef(2, 2, 1);
	glColor3f(1.0, 0, 0);
	glBegin(GL_LINE_LOOP);

	//int points = 100;
	float radius = 1.5;
	for (int i = 0; i <= 180; i++) {
		circleangle = PI * i / 180.0;
		glVertex2f(radius * cos(circleangle),
				radius * (float) sin(circleangle));
		if (i % 20 == 0) {
			radius = 1.0;
		} else if (i % 4 == 0) {
			radius = 1.3;
		}
		glVertex2f(radius * cos(circleangle),
				radius * (float) sin(circleangle));
		radius = 1.5;
	}
	glEnd();
	glTranslatef(1, 2.7, -10);

	glBegin(GL_LINES);
	float currangle = 0.0;

	currangle += PI * cvelocity / maxvelocity;

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-4.7, -0.95, -10);
	glVertex3f(-4.7 - 1.8 * cos(currangle), -0.95 + 1.8 * sin(currangle), -10);
	glVertex3f(-4.7, -0.9, -10);
	glVertex3f(-4.7 - 1.8 * cos(currangle), -0.95 + 1.8 * sin(currangle), -10);
	glEnd();
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

}
