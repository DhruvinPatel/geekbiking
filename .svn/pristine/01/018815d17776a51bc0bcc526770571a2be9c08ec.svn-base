
#ifndef HUD_H_
#define HUD_H_

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
using namespace std;

static int aaa = 60;
static int score = 0;
void initBackGround(const char* filename);
static float maxvelocity = 155.0;
GLuint loadTexture1(Image* image);
void drawHUD(float x, float y, float z, float _angle,int a,int b, float cvelocity);


#endif /* HUD_H_ */
