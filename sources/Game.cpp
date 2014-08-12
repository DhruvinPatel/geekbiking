//============================================================================
// Name        : Game.cpp
// Author      : Rohit Pruthi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include <windows.h>
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
#include <GL/freeglut.h>
#endif

#define PI 3.141592656
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "physics.h"
#include "imageloader.h"
#include "vec3f.h"
#include "Kollision.h"
#include "obj.h"
#include "hud.h"
#include "Game.h"
#include "name.h"
#include <QMainWindow>
using namespace std;

float _angle = 60.0f;
float _z = 0.0f;
float _x = 0.0f;
float _y = 0.0f;
float _phi = 0.0f;
float _banking = 0.0f;
PhysicsEngine myPhysicsEngine = PhysicsEngine();
bool isPressed[] = { false, false, false, false };
bool collision = false;
bool qcollision[] = { false, false, false, false, false, false, false, false,
		false };
bool* qwerty;
bool iscollision = false;
int positionofthebox = -1;
bool disapear[9] = { false, false, false, false, false, false, false, false,
		false };
int type[9] = { 1, 0, 0, 0, 0, 1, 0, 0, 0 };
GLMmodel *_myModel;
GLMmodel *_myPlayer;
GLMmodel *mymodel;
GLMmodel *mymodel2;
class node {
public:
	string name;
	int points;
};
int findscore();
void change(node* players, int j, int p, string n);
void quit();

void handleKeypress(unsigned char key, int x, int y) {
	/** handleKeypress : handles the behavior of game when a keyboard button
	 * is pressed. This function only works for all keys that have
	 * ASCII values.
	 */
	switch (key) {
	case 27: //Escape key
		aaa = -1;
		break;
	case 'r':
		myPhysicsEngine.reset();
		break;
	case 32: //Space key
		myPhysicsEngine.jump();
		break;
	}
}

void handleKeyUp(unsigned char key, int x, int y) {
	/** handleKeyUp : handles the behavior of game when a keyboard button
	 * is released. This function only works for all keys that have
	 * ASCII values.
	 */
}

void keySpecial(int key, int x, int y) {
	/** keySpecial : handles the behavior of game when a keyboard button
	 * is pressed. This function only works for all special keys like arrow keys
	 */
	switch (key) {
	case GLUT_KEY_RIGHT:
		isPressed[3] = true;
		break;
	case GLUT_KEY_LEFT:
		isPressed[2] = true;
		break;
	case GLUT_KEY_UP:
		isPressed[0] = true;
		break;
	case GLUT_KEY_DOWN:
		isPressed[1] = true;
		break;
	}
}

void keySpecialUp(int key, int x, int y) {
	/** keySpecial : handles the behavior of game when a keyboard button
	 * is released. This function only works for all special keys like arrow keys
	 */
	switch (key) {
	case GLUT_KEY_RIGHT:
		isPressed[3] = false;
		break;
	case GLUT_KEY_LEFT:
		isPressed[2] = false;
		break;
	case GLUT_KEY_UP:
		isPressed[0] = false;
		break;
	case GLUT_KEY_DOWN:
		isPressed[1] = false;
		break;
	}
}

void handleResize(int w, int h) {
	/** handleResize : handles the perspective when window is resized.
	 * Since we've used fullscreen, this function isn't being used right now.
	 */
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double) w / (double) h, 0.1, 500.0);
}

void functionforthesakeofterrain() {
	/** functionforthesakeofterrain: draws the obstacles at given coordinates
	 * and handles the behavior of game when an obstacle is collected.
	 */
	if (tracknumber == 1) {
		Vec3f v1(-2, 1, 5);
		Vec3f v2(-60 * 4, 0.5, 24 * 4);
		Vec3f v3(-27 * 4, 0.3, -110 * 4);
		Vec3f v4(-86 * 4, 0.3, 82 * 4);
		Vec3f v5(26.3 * 4, 0.3, 88.9 * 4);
		Vec3f v6(106 * 4, 0.3, 26.14 * 4);
		Vec3f v7(82 * 4, 0.3, 3.75 * 4);
		Vec3f v8(85 * 4, 5.9, -2.62 * 4);
		Vec3f v9(350 * 4, 0.3, 200 * 4);

		sbox ob;
		ob.initialize(30.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, v1,
				v2, v3, v4, v5, v6, v7, v8, v9);
		ob.collision2(_x + 2 * sin(PI * _angle / 180), _y,
				_z + 2 * cos(PI * _angle / 180), qcollision);
		int pos = ob.detect(qcollision);
		if (pos != -1) {
			/* give a position verification command for the sake of
			 * disappearing / not disappearing objects.
			 */
			if (type[pos] == 0)		// it is a bonus marker;
					{
				disapear[pos] = true;
			} else {
				//boolean collision should get true till it gets out to avoid static behavior
				iscollision = true;
				positionofthebox = -1;
			}
		} else {
			iscollision = false;
		}

	}

	else if (tracknumber == 2) {
		Vec3f v1(-2, 1, 5);
		Vec3f v2(31, -0.7, 36.36);
		Vec3f v3(308, -0.7, -139.8);
		Vec3f v4(132, -0.7, -433.56);
		Vec3f v5(-105, -0.7, -439);
		Vec3f v6(-364, -2.7, -153.94);
		Vec3f v7(-225, -2.7, -153.94);
		Vec3f v8(85 * 4, 5.9, -2.62 * 4);
		Vec3f v9(350 * 4, 0.3, 200 * 4);

		sbox ob;
		ob.initialize(15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, v1,
				v2, v3, v4, v5, v6, v7, v8, v9);
		ob.collision2(_x + 2 * sin(PI * _angle / 180), _y,
				_z + 2 * cos(PI * _angle / 180), qcollision);
		int pos = ob.detect(qcollision);
		if (pos != -1) {
			/* give a position verification command for the sake of
			 * disappearing / not disappearing objects.
			 */
			if (type[pos] == 0)		// it is a bonus marker;
					{
				disapear[pos] = true;
			} else {
				//boolean collision should get true till it gets out to avoid static behavior.
				iscollision = true;
				positionofthebox = -1;
			}
		} else {

			iscollision = false;
		}

	}

	else if (tracknumber == 3) {
		Vec3f v1(-220, 0.7, -355.47);
		Vec3f v2(-107, -0.7, -367);
		Vec3f v3(-272, -0.7, -368);
		Vec3f v4(56, -0.7, -366);
		Vec3f v5(287, -0.7, 309);
		Vec3f v6(224, -0.7, 309);
		Vec3f v7(66, -0.7, 61);
		Vec3f v8(241.65, 1.3, -165);
		Vec3f v9(350 * 4, 0.3, 200 * 4);

		sbox ob;
		ob.initialize(15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, v1,
				v2, v3, v4, v5, v6, v7, v8, v9);
		ob.collision2(_x + 2 * sin(PI * _angle / 180), _y,
				_z + 2 * cos(PI * _angle / 180), qcollision);
		int pos = ob.detect(qcollision);
		cout << "pos:" << pos << endl;
		if (pos != -1) {
			/* give a position verification command for the sake of
			 * disappearing / not disappearing objects.
			 */
			if (type[pos] == 0)		// it is a bonus marker;
					{
				disapear[pos] = true;
			} else {
				//boolean collision should get true till it gets out to avoid static behavior
				iscollision = true;
				positionofthebox = -1;
			}
		} else {

			iscollision = false;
		}
	}

	else if (tracknumber == 4) {
		Vec3f v1(339, 2.0, -424);
		Vec3f v2(580, -2, -288);
		Vec3f v3(108, -0.7, -440);
		Vec3f v4(310, -0.7, 259);
		Vec3f v5(-119, 0.3, -87);
		Vec3f v6(-199, 0.3, 240.9);
		Vec3f v7(-274, 1.2, 97);
		Vec3f v8(-274, 1.2, 97);
		Vec3f v9(350 * 4, 0.3, 200 * 4);
		sbox ob;
		ob.initialize(15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, v1,
				v2, v3, v4, v5, v6, v7, v8, v9);
		ob.collision2(_x + 2 * sin(PI * _angle / 180), _y,
				_z + 2 * cos(PI * _angle / 180), qcollision);
		int pos = ob.detect(qcollision);
		cout << "pos:" << pos << endl;
		if (pos != -1) {
			/* give a position verification command for the sake of
			 * disappearing / not disappearing objects.
			 */
			if (type[pos] == 0)		// it is a bonus marker;
					{
				disapear[pos] = true;
			} else {
				//boolean collision should get true till it gets out to avoid static behavior
				iscollision = true;
				positionofthebox = -1;
			}
		} else {
			iscollision = false;
		}
	}

	else if (tracknumber == 5) {
		Vec3f v1(282, -0.1, 0.01);
		Vec3f v2(-350, 0.3, -34);
		Vec3f v3(381, -0.7, -1.4);
		Vec3f v4(351, 0.3, -360);
		Vec3f v5(-252, -2.7, -98);
		Vec3f v6(-228, -0.7, 285);
		Vec3f v7(389, -0.7, 98);
		Vec3f v8(241.65, 1.3, -165);
		Vec3f v9(350 * 4, 0.3, 200 * 4);

		sbox ob;
		ob.initialize(15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, v1,
				v2, v3, v4, v5, v6, v7, v8, v9);
		ob.collision2(_x + 2 * sin(PI * _angle / 180), _y,
				_z + 2 * cos(PI * _angle / 180), qcollision);
		int pos = ob.detect(qcollision);
		cout << "pos:" << pos << endl;
		if (pos != -1) {
			/* give a position verification command for the sake of
			 * disappearing / not disappearing objects.
			 */
			if (type[pos] == 0)		// it is a bonus marker;
					{
				disapear[pos] = true;
			} else {
				//boolean collision should get true till it gets out to avoid static behavior
				iscollision = true;
				positionofthebox = -1;
			}
		} else {

			iscollision = false;
		}
	}
}

void drawScene() {
	/** drawScene : function to draw the scene. This function is called every 25 ms */
	myPhysicsEngine.simulate(isPressed, _x, _z, iscollision);
	_phi = myPhysicsEngine.getPhi();
	_angle = myPhysicsEngine.getAngle();
	_y = myPhysicsEngine.getY();
	_x = myPhysicsEngine.getX();
	_z = myPhysicsEngine.getZ();
	_banking = myPhysicsEngine.getBanking(isPressed);
	float _v = myPhysicsEngine.getVelocity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.8, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt((_x + 25 * sin(PI * _angle / 180)), _y + 7,
			_z + 25 * cos(PI * _angle / 180), _x, _y + 4, _z, 0, 1, 0);
	if (!practice) { // if the track is not of practice type
		functionforthesakeofterrain();
		drawObstacle(mymodel, mymodel2, disapear, type, tracknumber);
		score = findscore();
	}
	drawBike(_x, _y + 1.5, _z, _angle, _banking, getMyTerrainNormal(_x, _z),
			_myModel, _myPlayer);
	drawHUD(_x, _y, _z, _angle, aaa, score, _v);

	drawTerrain();

	if (_y > getHeight(_x, _z))
		myPhysicsEngine.setAir(true);

	if (_y <= getHeight(_x, _z))
		myPhysicsEngine.setAir(false);
	if (aaa < 0) {
		quit();
	}
	if (_x >= 510 || _z >= 510 || _x <= -510 || _z <= -510)
		myPhysicsEngine.reset();
	glutSwapBuffers();
}
int temp = 0; // the number of times the update function is called.
void update(int value) {

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
	temp += 1;
	if (temp % 40 == 0) {
		if (!practice)
			aaa -= 1;
		else
			aaa = 0;
		temp = 0;
	}
}

void initRendering() {
	/** Function used to load the required objects and textures into memory */
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	_myModel = initObject("objects/Kroserica_simple2.obj.txt");
	mymodel = initObject("objects/can.obj.txt");
	mymodel2 = initObject("objects/cube_texture.obj.txt");
	_myPlayer = initObject("objects/Kamen Rider Black SD.obj.txt");
	initObstacle();
	initBackGround("sources/images/hud.bmp");

}

int findscore() {
	/** Uses number of bonus markers collected to calculate final score of player*/
	int answer = 0;
	for (int i = 0; i < 9; i++) {
		if (disapear[i])
			answer += 50;
	}
	return answer;
}

void run(int argc, char *argv[]) {
	glutInit(&argc, argv);
}

int start(int trackno, bool isPractice) {
	/** This function starts a new OpenGL window with given tracknumber */
	char *myargv[1];
	int myargc = 1;
	myargv[0] = strdup("Games");
	glutInit(&myargc, myargv);
	aaa = 60;
	myPhysicsEngine.reset();
	tracknumber = trackno;
	practice = isPractice;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	glutCreateWindow("Games");
	initRendering();
	glutDisplayFunc(drawScene);
	if (trackno == 1) {
		initTerrain("tracks/hmap2.bmp", "tracks/tmap2.bmp");
	} else if (trackno == 2) {
		initTerrain("tracks/hmap6.bmp", "tracks/tmap6.bmp");
	} else if (trackno == 3) {
		initTerrain("tracks/hmap7.bmp", "tracks/tmap7.bmp");
	} else if (trackno == 4) {
		initTerrain("tracks/hmap8.bmp", "tracks/tmap8.bmp");
	} else if (trackno == 5) {
		initTerrain("tracks/hmap9.bmp", "tracks/tmap9.bmp");
	} else if (trackno == 6) {
		initTerrain("tracks/hmp1.bmp", "tracks/tmp1.bmp");
	} else if (trackno == 7) {
		initTerrain("tracks/hmp2.bmp", "tracks/tmp2.bmp");
	} else if (trackno == 8) {
		initTerrain("tracks/hmp3.bmp", "tracks/tmp3.bmp");
	} else if (trackno == 9) {
		initTerrain("tracks/hmp4.bmp", "tracks/tmp4.bmp");
	}

	glutIdleFunc(drawScene);
	glOrtho(-100, 100, -100, 100, -100, 100);
	glTranslatef(0.0, 0.0, 0.0);
	glutKeyboardFunc(handleKeypress);
	glutKeyboardUpFunc(handleKeyUp);
	glutSpecialFunc(keySpecial);
	glutSpecialUpFunc(keySpecialUp);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutFullScreen();
	glutMainLoop();
	cout << "Exited main loop";
	return EXIT_SUCCESS;
}

void change(node* players, int j, int p, string n) {
	/** Inserts the highscore in the file if the score is in top 5 */
	if (players[j].points < p) {
		while (j < 5) {
			int tempp = players[j].points;
			string tempn = players[j].name;

			players[j].points = p;
			players[j].name = n;
			p = tempp;
			n = tempn;
			j++;
		}

	} else if (j < 4)
		change(players, j + 1, p, n);
}

void quit() {
	/** quit : writes the high score to save file and also quit the game. */
	string d = text.toLocal8Bit().constData();
	node players[5];
	int i = 0;
	string STRING = "";
	ifstream myreadfile;
	myreadfile.open("data.txt");
	while (!myreadfile.eof() && i < 5) {
		string a = STRING;
		getline(myreadfile, STRING);
		stringstream divide(STRING);
		do {
			string sub;
			divide >> players[i].name >> players[i].points >> sub;
		} while (divide);
		i++;
	}
	myreadfile.close();

	change(players, 0, score, text.toStdString());
	fstream myfile;
	d = d + STRING;
	int j = 0;
	myfile.open("data.txt");
	while (j < 5) {

		myfile << players[j].name << "     " << players[j].points << "\n";
		j++;
	}
	myfile.close();
//	cleanup();
	glutLeaveMainLoop();
}
