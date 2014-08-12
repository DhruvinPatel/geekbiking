#ifndef BOX_H_
#define BOX_H_

//#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//#include "imageloader.h"
#include "vec3f.h"
//#include "terr.h"
//#include "glm.h"

class box {
private:
	Vec3f max;
	Vec3f min;
public:
	box() {
		min[0] = 0;
		min[1] = 0;
		min[2] = 0;
		max[0] = 0;
		max[1] = 0;
		max[2] = 0;
	}
	box(float x1, float y1, float z1, float x2, float y2, float z2) {
		min[0] = x1;
		min[1] = y1;
		min[2] = z1;
		max[0] = x2;
		max[1] = y2;
		max[2] = z2;
	}

	void _drawBox() {
		glScalef(1.0,1.0,1.0);
		glBegin(GL_QUADS);          // Begin drawing the color cube with 6 quads
		// Top face (y = 1.0f)
		// Define vertices in counter-clockwise (CCW) order with normal pointing out
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(min[0], min[1], max[2]);
		glVertex3f(max[0], min[1], max[2]);
		glVertex3f(max[0], min[1], min[2]);
		glVertex3f(min[0], min[1], min[2]);

		// Bottom face (y = -1.0f)
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(min[0], max[1], min[2]);
		glVertex3f(max[0], max[1], min[2]);
		glVertex3f(max[0], max[1], max[2]);
		glVertex3f(min[0], max[1], max[2]);

		// Front face  (z = 1.0f)
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(min[0], min[1], min[2]);
		glVertex3f(max[0], min[1], min[2]);
		glVertex3f(max[0], max[1], min[2]);
		glVertex3f(min[0], max[1], min[2]);

		// Back face (z = -1.0f)
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(min[0], max[1], max[2]);
		glVertex3f(max[0], max[1], max[2]);
		glVertex3f(max[0], min[1], max[2]);
		glVertex3f(min[0], min[1], max[2]);

		// Left face (x = -1.0f)
		glColor3f(0.5f, 0.5f, 0.0f);
		glVertex3f(max[0], min[1], min[2]);
		glVertex3f(max[0], min[1], max[2]);
		glVertex3f(max[0], max[1], max[2]);
		glVertex3f(max[0], max[1], min[2]);

		// Right face (x = 1.0f)
		glColor3f(0.0f, 0.5f, 0.5f);
		glVertex3f(min[0], min[1], max[2]);
		glVertex3f(min[0], min[1], min[2]);
		glVertex3f(min[0], max[1], min[2]);
		glVertex3f(min[0], max[1], max[2]);
		glEnd();

	}
	bool collision(float xx , float yy , float zz)
		{
			return ((xx - min[0])*(max[0]-xx)>0)&&((yy - min[1])*(max[1]-yy)>0)&&((zz - min[2])*(max[2]-zz)>0);
		}
};

#endif
