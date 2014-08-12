//============================================================================
// Name        : Game.h
// Author      : Rohit Pruthi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include <windows.h>
#ifndef GAME_H_
#define GAME_H_

#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <math.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define PI 3.141592656
#include "physics.h"
#include "imageloader.h"
#include "vec3f.h"

#include "obj.h"
#include "hud.h"

using namespace std;

static int tracknumber =0;
static bool practice;

void handleKeypress(unsigned char key, int x, int y);

void handleKeyUp(unsigned char key, int x, int y);

void handleResize(int w, int h);

void drawScene();

void update(int value);

void initRendering();

int start(int trackno, bool isPractice);

#endif
