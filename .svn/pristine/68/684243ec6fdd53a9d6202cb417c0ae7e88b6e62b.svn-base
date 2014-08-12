#ifndef OBJ_H_
#define OBJ_H_

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

#include "render.h"
#include "imageloader.h"
#include "vec3f.h"
#include "hud.h"

using namespace std;

GLMmodel* initObject(const char* filename);
//static float phi = 0;
//float GiveMePhi ();

void drawBike(float x, float y, float z, float angle, float banking, Vec3f normal,
		GLMmodel* myModel, GLMmodel* myPlayer);
void drawObstacle(GLMmodel* mymodel,GLMmodel* mymodel2, bool* disapear ,int *col, int tracknumber);
#endif /* OBJ_H_ */
