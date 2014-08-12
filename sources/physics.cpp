#define PI 3.141592656
#define TIME 0.025f
# define gravity 20
#include <math.h>
#include <stdio.h>
#include "physics.h"

float getHeight(float x, float z) {
	/** getHeight: compute the height of the terrain at given x and z coordinates */
	float y;
	y = getMyTerrainHeight((int) x, (int) z);
	int yy1, y2, y3, y4;
	yy1 = getMyTerrainHeight((int) x, (int) z);
	y2 = getMyTerrainHeight((int) x + 1, (int) z);
	y3 = getMyTerrainHeight((int) x, (int) z + 1);
	y4 = getMyTerrainHeight((int) x + 1, (int) z + 1);
	if ((x - (int) x) + (z - (int) z) < 1)
		y = intersection((int) x, (int) yy1, (int) z, (int) x + 1, (int) y2,
				(int) z, (int) x, (int) y3, (int) z + 1, x, z);
	else
		y = intersection((int) x + 1, (int) y2, (int) z, (int) x, (int) y3,
				(int) z + 1, (int) x + 1, (int) y4, (int) z + 1, x, z);
	y += 0.5f;
	return y;
}

float getTangent1(float x1, float z1, float angle) {
	/** getTangent1: compute the tangent of the surface at given x and z coordinates
	 *  along given angle */
	float y1 = (float) getHeight(x1, z1);
	float y2 = (float) getHeight(x1 + 0.1 * sin(PI * angle / 180),
			z1 + 0.1 * cos(PI * angle / 180));
	float answer = (y2 - y1) * 10;
	return answer;
}

PhysicsEngine::PhysicsEngine() {
	/** PhysicsEngine: a class for physics engine which is used to find coordinates
	 * of bike as time progresses. The parameters for this class are:
	 * angle : angle of bike in x-z plane from positive z-axis
	 * phi : angle of bike between x-z plane and it's direction
	 * velocity : velocity of bike along radial direction
	 * acceleration : acceleration of bike along radial direction
	 * displacement : displacement of bike along radial direction
	 * inAir : checks whether the bike is in air or not
	 * airDisplacement : the displacement vector in case the bike is in air
	 * airVelocity : the velocity vector in case the bike is in air
	 * airAcceleration : the acceleration vector in case the bike is in air
	 * x : the x coordinates
	 * y : the y coordinates
	 * z : the z coordinates
	 * banking : the angle of banking of bike.
	 * The constructor sets all of them to their default values.
	 */
	angle = 0.0f;
	phi = 0.0f;
	velocity = 0.0f;
	acceleration = 0.0f;
	displacement = 0.0f;
	inAir = false;
	airDisplacement = Vec3f(0.0f, 0.0f, 0.0f);
	airVelocity = Vec3f(0.0f, 0.0f, 0.0f);
	airAcceleration = Vec3f(0.0f, -40.0f, 0.0f);
	x = 0.0f;
	y = 1.0f;
	z = 0.0f;
	banking = 0.0f;
}

float PhysicsEngine::getAngle() {
	/** getAngle : returns the angle of bike along x-z plane with x axis */
	return angle;
}

float PhysicsEngine::getX() {
	/** getX : returns the x coordinate of bike */
	return x;
}

float PhysicsEngine::getY() {
	/** getY : returns the y coordinate of bike */
	return y;
}

float PhysicsEngine::getZ() {
	/** getZ : returns the z coordinate of bike */
	return z;
}

float PhysicsEngine::getPhi() {
	/** getPhi : returns the angle of bike with x-z plane */
	return phi;
}

float PhysicsEngine::getVelocity() {
	/** getVelocity : returns the velocity of bike along radial direction */
	return velocity;
}

void PhysicsEngine::simulate(bool* buttonsPressed, float xx, float zz,
		bool collision) {
	/** simulate : update the values of all the parameters.
	 * Call this function every time you draw the scene.
	 * Uses a very primitive method based on Newton's laws */
	if (inAir) {
		airVelocity += airAcceleration * TIME;
		airDisplacement = airVelocity * TIME
				- 0.5 * airAcceleration * TIME * TIME;
		x -= airDisplacement[0] * sin(angle * PI / 180);
		z -= airDisplacement[0] * cos(angle * PI / 180);
		y += airDisplacement[1];
	} else {
		float p = getTangent1(xx, zz, angle);
		phi = atan(p);
		acceleration = 0.0f;

		if (buttonsPressed[0]) {
			if (collision) {
				velocity = 0.0f;
				acceleration = 0.0f;
			} else {
				acceleration += 25.0f + gravity * sin(phi);
				if (velocity >= 6 * acceleration) {
					acceleration = 0.0f + gravity * sin(phi);
				}
			}
		}

		else {
			if (velocity > 0.0f) {
				acceleration += (-2.75f + gravity * sin(phi));
			} else {
				if (!(sin(phi) == 0)) {
					acceleration = acceleration - 2.75 + gravity * sin(phi); //2
				} else {
					acceleration = 0;
					velocity = 0;
				}
			}
		}

		if (buttonsPressed[1]) {

			if (velocity > 0) {
				acceleration = acceleration - 16.5f + gravity * sin(phi); //5.0/(1);
			} else {
				cout << "ispressed 1 = true";
				if (velocity <= 0) {
					velocity = -5.4f;
				}
			}
		}

		if (buttonsPressed[2]) {
			if (velocity > 0.001f)
				angle += 2.5f;
			if (velocity < -0.001f)
				angle -= 2.5f;
			cout << ":" << angle << "yo2";
		}
		if (buttonsPressed[3]) {
			if (velocity > 0.1f)
				angle -= 1.25f;
			if (velocity < -0.1f)
				angle += 1.25f;
			cout << ":" << angle << "yo3";
		}
		velocity += acceleration * TIME;
		displacement = (velocity * TIME) - (0.5 * acceleration * TIME * TIME);
		x -= displacement * sin(angle * PI / 180) * cos(phi);
		z -= displacement * cos(angle * PI / 180) * cos(phi);
		y -= displacement * sin(phi);
		if (y < getHeight(x, z))
			y = getHeight(x, z);
	}
}

void PhysicsEngine::setAir(bool arg0) {
	/** setAir : update the value of inAir variable. */
	if (arg0 && !inAir) {
		airVelocity[0] = velocity;
		airVelocity[1] = 0.0f;
		inAir = true;
	}
	if (!arg0 && inAir) {
		acceleration = 0.0f;
		velocity = airVelocity[0];
		phi = 0.0f;
		inAir = false;
	}
}

/* reset : reset the coordinates of system */
void PhysicsEngine::reset() {
	x = 0.0f;
	y = 1.0f;
	z = 0.0f;
	velocity = 0.0f;
	acceleration = 0.0f;
	inAir = false;
}

/* getBanking : return the value of banking angle with bike */
float PhysicsEngine::getBanking(bool* buttonsPressed) {
	if (inAir) {
		if (banking > 0)
			banking -= 0.25f;
		if (banking < 0)
			banking += 0.25f;
	} else {
		if (buttonsPressed[2] && !buttonsPressed[3]) {
			banking += 0.5f;
		} else if (buttonsPressed[3] && !buttonsPressed[2]) {
			banking -= 0.5f;
		} else if (buttonsPressed[2] && buttonsPressed[3]) {
			if (banking > 0)
				banking -= 1.0f;
			if (banking < 0)
				banking += 1.0f;
		} else {
			if (banking > 0)
				banking -= 1.0f;
			if (banking < 0)
				banking += 1.0f;
		}
		if (banking > 0.3 * velocity && velocity >= 0)
			banking = 0.3 * velocity;
		if (banking < -0.3 * velocity && velocity >= 0)
			banking = -0.3 * velocity;

	}
	return banking;
}

void PhysicsEngine::jump() {
	/** jump the bike */
	if (!inAir) {
		if (velocity < 30) {
			return;
			airVelocity[0] = velocity * cos(phi);
			airVelocity[1] = velocity * sin(phi) + 0;
			cout << "1" << endl;
		} else if (velocity < 65) {
			airVelocity[0] = velocity * cos(phi);
			airVelocity[1] = velocity * sin(phi) + 10;
			cout << "2" << endl;
		} else if (velocity < 100) {
			airVelocity[0] = velocity * cos(phi);
			airVelocity[1] = velocity * sin(phi) + 20;
			cout << "3" << endl;
		}

		inAir = true;
	} else {
		if (abs(y - getHeight(x, z)) < 3.0f) {
			if (velocity < 30) {
				return;
				airVelocity[0] = velocity * cos(phi);
				airVelocity[1] = velocity * sin(phi) + 0;
				cout << "1" << endl;
			} else if (velocity < 65) {
				airVelocity[0] = velocity * cos(phi);
				airVelocity[1] = velocity * sin(phi) + 10;
				cout << "2" << endl;
			} else if (velocity < 100) {
				airVelocity[0] = velocity * cos(phi);
				airVelocity[1] = velocity * sin(phi) + 20;
				cout << "3" << endl;
			}
		}
	}
}
