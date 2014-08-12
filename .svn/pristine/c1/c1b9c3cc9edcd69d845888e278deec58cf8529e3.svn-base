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
//#include "terr.h"
#include <sstream>
#include "obj.h"
#include "hud.h"
#include "physics.h"
#include <math.h>

#define PI 3.141592655
using namespace std;

GLMmodel* initObject(const char* filename) {
	/** initObject: Reads a model description from a Wavefront .OBJ file.
	 * Returns a pointer to the created object which should be free'd with
	 * glmDelete().
	 *
	 * filename - name of the file containing the Wavefront .OBJ format data.
	 *
	 */
	GLMmodel* myModel = glmReadOBJ(filename);
	return myModel;
}
void function_draw (GLMmodel* mymodel,bool* disapear,int i,int* j,int x ,int y,int z)
{

	glPushMatrix();

	if (!disapear[i]) {
		glTranslatef(x, y, z);
		glScalef(2.5, 2.5, 2.5);
		renderObstacle(mymodel, j[i]);
	}
	glPopMatrix();

}

void drawBike(float x, float y, float z, float angle, float banking,
		Vec3f normal, GLMmodel* myModel, GLMmodel* myPlayer) {
	/** renders bike at (x,y,z)
	 * rotate it to the given argument angle and banking angle
	 * banking - angle formed while tilting
	 */

	glPushMatrix();

	glTranslatef(0.0f, 0.0f, 0.0f);
	glTranslatef(x, y, z);
	glScalef(0.15f, 0.15f, 0.15f);
	Vec3f direction = Vec3f();
	direction = {-sin(angle*PI/180),0.0f,cos(angle * PI / 180)};
	float phi = 90 - ((acos(normal.dot(direction)) * 180) / PI);
	if (y - getHeight(x, z) > 5.5f) {
		phi = 0;
	}
	glRotatef(phi, cos(angle * PI / 180), 0.0f, sin(angle * PI / 180));
	glRotatef(banking, sin(angle * PI / 180), 0.0f, cos(angle * PI / 180));

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	renderObject(myModel); //renders bike
	glScalef(20.0f, 20.0f, 20.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.6f, 0.25f);
	glColor3f(0.0f, 0.0f, 0.0f);
	renderObject(myPlayer);

	glPopMatrix();

}

void drawObstacle(GLMmodel* mymodel, GLMmodel* mymodel2, bool* disapear,
		int * type, int tracknumber) {
	/** drawObstacle : Draws the given model to well defined coordinates
	 * according to given track number and if the object is collected as
	 * a bonus or now */

	switch (tracknumber) {
	case 1:
		function_draw(mymodel2,disapear,0,type,-2,1 ,5);
		function_draw(mymodel,disapear,1,type,-60 * 4, 0.5, 24 * 4);
		function_draw(mymodel,disapear,2,type,-27 * 4, 0.3, -110 * 4);
		function_draw(mymodel,disapear,3,type,-86 * 4, 0.3, 82 * 4);
		function_draw(mymodel,disapear,4,type,26.3 * 4, 0.3, 88.9 * 4);
		function_draw(mymodel2,disapear,5,type,106 * 4, 0.3, 26.14 * 4);
		function_draw(mymodel,disapear,6,type,82 * 4, 0.3, 3.75 * 4);
		function_draw(mymodel,disapear,7,type,85 * 4, 5.9, -2.62 * 4);
		function_draw(mymodel,disapear,8,type,350 * 4, 0.3, 200 * 4);
		break;
//		glPushMatrix();
//
//		if (!disapear[0]) {
//			glTranslatef(-2, 1, 5);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[0]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[1]) {
//			glTranslatef(-60 * 4, 0.5, 24 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[1]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[2]) {
//			glTranslatef(-27 * 4, 0.3, -110 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[2]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[3]) {
//			glTranslatef(-86 * 4, 0.3, 82 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[3]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[4]) {
//			glTranslatef(26.3 * 4, 0.3, 88.9 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[4]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[5]) {
//			glTranslatef(106 * 4, 0.3, 26.14 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[5]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[6]) {
//			glTranslatef(82 * 4, 0.3, 3.75 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[6]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[7]) {
//			glTranslatef(85 * 4, 5.9, -2.62 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[7]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[8]) {
//			glTranslatef(350 * 4, 0.3, 200 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[8]);
//		}
//		glPopMatrix();
//
	case 2:
		function_draw(mymodel2,disapear,0,type,-2,1 ,5);
		function_draw(mymodel,disapear,1,type,31, -0.7, 36.36);
		function_draw(mymodel,disapear,2,type,308, -0.7, -139.8);
		function_draw(mymodel,disapear,3,type,132, -0.7, -433.56);
		function_draw(mymodel,disapear,4,type,-105, -0.7, -439);
		function_draw(mymodel2,disapear,5,type,-364, -2.7, -153.94);
		function_draw(mymodel,disapear,6,type,-225, -2.7, -153.94);
		function_draw(mymodel,disapear,7,type,85 * 4, 5.9, -2.62 * 4);
		function_draw(mymodel,disapear,8,type,350 * 4, 0.3, 200 * 4);
		break;
//
//		glPushMatrix();
//
//		if (disapear[0]) {
//			glTranslatef(-2, 1, 5);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[0]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[1]) {
//			glTranslatef(31, -0.7, 36.36);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[1]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[2]) {
//			glTranslatef(308, -0.7, -139.8);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[2]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[3]) {
//			glTranslatef(132, -0.7, -433.56);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[3]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[4]) {
//			glTranslatef(-105, -0.7, -439);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[4]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[5]) {
//			glTranslatef(-364, -2.7, -153.94);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[5]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[6]) {
//			glTranslatef(-225, -2.7, -153.94);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[6]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[7]) {
//			glTranslatef(85 * 4, 5.9, -2.62 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[7]);
//		}
//		glPopMatrix();
//
//		glPushMatrix();
//		if (!disapear[8]) {
//			glTranslatef(350 * 4, 0.3, 200 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[8]);
//		}
//		glPopMatrix();
	case 3:
		function_draw(mymodel2,disapear,0,type,-220, 0.7, -355.47);
		function_draw(mymodel,disapear,1,type,-107, -0.7, -367);
		function_draw(mymodel,disapear,2,type,-272, -0.7, -368);
		function_draw(mymodel,disapear,3,type,56, -0.7, -366);
		function_draw(mymodel,disapear,4,type,287, -0.7, 309);
		function_draw(mymodel2,disapear,5,type,224, -0.7, 309);
		function_draw(mymodel,disapear,6,type,66, -0.7, 61);
		function_draw(mymodel,disapear,7,type,241.65, 1.3, -165);
		function_draw(mymodel,disapear,8,type,350 * 4, 0.3, 200 * 4);
		break;
//		glPushMatrix();
//
//		if (!disapear[0]) {
//			glTranslatef(-220, 0.7, -355.47);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[0]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[1]) {
//			glTranslatef(-107, -0.7, -367);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[1]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[2]) {
//			glTranslatef(-272, -0.7, -368);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[2]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[3]) {
//			glTranslatef(56, -0.7, -366);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[3]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[4]) {
//			glTranslatef(287, -0.7, 309);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[4]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[5]) {
//			glTranslatef(224, -0.7, 309);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[5]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[6]) {
//			glTranslatef(66, -0.7, 61);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[6]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[7]) {
//			glTranslatef(241.65, 1.3, -165);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[7]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[8]) {
//			glTranslatef(350 * 4, 0.3, 200 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[8]);
//		}
//		glPopMatrix();
//
//		break;
	case 4:
			function_draw(mymodel2,disapear,0,type,339, 2.0, -424);
			function_draw(mymodel,disapear,1,type,580, -2, -288);
			function_draw(mymodel,disapear,2,type,-272, -0.7, -368);
			function_draw(mymodel,disapear,3,type,108, -0.7, -440);
			function_draw(mymodel,disapear,4,type,-119, -0.3, -87);
			function_draw(mymodel2,disapear,5,type,-199, 0.3, 240.9);
			function_draw(mymodel,disapear,6,type,-274, 1.2, 97);
			function_draw(mymodel,disapear,7,type,-274, 1.2, 97);
			function_draw(mymodel,disapear,8,type,350 * 4, 0.3, 200 * 4);
			break;
//		glPushMatrix();
//
//		if (disapear[0]) {
//			glTranslatef(339, 2.0, -424);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[0]);
//		}
//		if (!disapear[1]) {
//			glTranslatef(580, -2, -288);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[1]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[2]) {
//			glTranslatef(108, -0.7, -440);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[2]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[3]) {
//			glTranslatef(310, -0.7, 259);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[3]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[4]) {
//			glTranslatef(-119, -0.3, -87);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[4]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[5]) {
//			glTranslatef(-199, 0.3, 240.9);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[5]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[6]) {
//			glTranslatef(-274, 1.2, 97);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[6]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[7]) {
//			glTranslatef(-274, 1.2, 97);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[7]);
//		}
//		glPopMatrix();
//
//		glPushMatrix();
//		if (!disapear[8]) {
//			glTranslatef(350 * 4, 0.3, 200 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[8]);
//		}
//		glPopMatrix();
//
//		break;
case 5:

	function_draw(mymodel2,disapear,0,type,282, -0.1, 0.01);
	function_draw(mymodel,disapear,1,type,-350, 0.3, -34);
	function_draw(mymodel,disapear,2,type,381, -0.7, -1.4);
	function_draw(mymodel,disapear,3,type,351, 0.3, -360);
	function_draw(mymodel,disapear,4,type,-252, -2.7, -98);
	function_draw(mymodel2,disapear,5,type,-228, -0.7, 285);
	function_draw(mymodel,disapear,6,type,389, -0.7, 98);
	function_draw(mymodel,disapear,7,type,241.65, 1.3, -165);
	function_draw(mymodel,disapear,8,type,350 * 4, 0.3, 200 * 4);
	break;

//		glPushMatrix();
//		if (disapear[0]) {
//			glTranslatef(282, -0.1, 0.01);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[0]);
//		}
//		if (!disapear[1]) {
//			glTranslatef(-350, 0.3, -34);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[1]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[2]) {
//			glTranslatef(381, -0.7, -1.4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[2]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[3]) {
//			glTranslatef(351, 0.3, -360);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[3]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[4]) {
//			glTranslatef(-252, -2.7, -98);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[4]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[5]) {
//			glTranslatef(-228, -0.7, 285);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel2, type[5]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[6]) {
//			glTranslatef(389, -0.7, 98);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[6]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[7]) {
//			glTranslatef(241.65, 1.3, -165);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[7]);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		if (!disapear[8]) {
//			glTranslatef(350 * 4, 0.3, 200 * 4);
//			glScalef(2.5, 2.5, 2.5);
//			renderObstacle(mymodel, type[8]);
//		}
//		glPopMatrix();
//		break;
	}
}

