#ifndef KOLLISION_H_
#define KOLLISION_H_

#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "vec3f.h"

					//To change numbers : change no,readius[],pt1[]....initialize , in game : disapear add more false
class sbox {
private:

	int no =9 ;
	float radius[9] ;
	Vec3f pt1[9] ;

public:

	void initialize(float r1,float r2,float r3,float r4,float r5,float r6,float r7,float r8 ,float r9,Vec3f v1 , Vec3f v2,Vec3f v3,Vec3f v4,Vec3f v5,Vec3f v6,Vec3f v7,Vec3f v8,Vec3f v9)
		{
			radius[0]=r1;
			radius[1]=r2;
			radius[2]=r3;
			radius[3]=r4;
			radius[4]=r5;
			radius[5]=r6;
			radius[6]=r7;
			radius[7]=r8;
			radius[8]=r9;
			 pt1[0]=v1;
			 pt1[1]=v2;
			 pt1[2]=v3;
			 pt1[3]=v4;
			 pt1[4]=v5;
			 pt1[5]=v6;
			 pt1[6]=v7;
			 pt1[7]=v8;
			 pt1[8]=v9;
		}
float distance (float xx , float yy , float zz,Vec3f p1)
	{
		return (xx-p1[0])*(xx-p1[0]) + (yy - p1[1])*(yy - p1[1]) + (zz - p1[2])*(zz - p1[2]);
	}



	int detect(bool * ary)
		{
			for (int i =0 ; i<no ; i++)
				{
					if(ary[i])
						{
						return i;
						}

				}
			return -1;
		}

	void collision2(float xx , float yy , float zz ,bool * ary)
		{

//		bool ary[]={false,false};
		ary[0]=false;
		ary[1]=false;
		ary[2]=false;
		ary[3]=false;
		ary[4]=false;
		ary[5]=false;
		ary[6]=false;
		ary[7]=false;
		ary[8]=false;
			//return ((xx - min[0])*(max[0]-xx)>0)&&((yy - min[1])*(max[1]-yy)>0)&&((zz - min[2])*(max[2]-zz)>0);
		for(int i = 0; i <no ;i++ )
			{
			float dista = distance(xx,yy,zz,pt1[i]);
			if(dista < radius[i])
							{
								//radius = 0;
								ary[i] = true;
								return ;
							}
						//return false;
					}

		return   ;
		}
		//float distance = distance(xx,yy,zz,pt1) ;

};

#endif
