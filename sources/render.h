/*
 * render.h
 *
 *  Created on: 03-Sep-2013
 *      Author: rohit
 */

#ifndef RENDER_H_
#define RENDER_H_

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
#include "glm.h"
#include "hud.h"
#include <math.h>

#define PI 3.141592655
using namespace std;

void initObstacle();
GLuint loadTexture2(Image* image);
void renderObject(GLMmodel *myModel);
void renderObstacle(GLMmodel *mymodel, int i);
#endif /* RENDER_H_ */
