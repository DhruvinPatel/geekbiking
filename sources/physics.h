/*
 * physics.h
 *
 *  Created on: 07-Aug-2013
 *      Author: rohit
 */

#ifndef PHYSICS_H_
#define PHYSICS_H_
#ifndef PI
#define PI 3.141592656
#endif
//#define TIME 0.025

#include <math.h>
#include "vec3f.h"
#include "terr.h"
float getHeight(float x, float z);
float getTerrainPhi(float x, float z, float angle);

class PhysicsEngine {
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
private:
	Vec3f airDisplacement;
	Vec3f airVelocity;
	Vec3f airAcceleration;
	float displacement;
	float angle;
	float phi;
	float velocity;
	//float initial;
	float acceleration;
	float banking;
	float x, y, z;
	bool inAir;
public:
	PhysicsEngine();
	void simulate(bool* buttonsPressed, float xx, float zz, bool collision);
	float getPhi();
	float getAngle();
	float ahead(float ac, float acc);
	float notahead(float b, float acc);
	float reverse(float b, float acc);
	float getX();
	float getY();
	float getZ();
	float getVelocity();
	void setAir(bool arg0);
	void reset();
	float abs(float vel) {
		if (vel < 0) {
			return -vel;
		} else {
			return vel;
		}
	}
	float getBanking(bool* buttonsPressed);
	void jump();
};

#endif /* PHYSICS_H_ */
