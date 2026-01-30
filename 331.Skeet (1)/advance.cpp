//
//  advance.cpp
//  Lab03
//
//  Created by Elijah Dodge on 1/30/26.
//


#include <cassert>
#include "advance.hpp"
#include "bird.h"

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32

/******************************************************************
* RANDOM

* These functions generate a random number.
****************************************************************/

int randomAdvanceInt(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);
   return num;
}
 
double randomAdvanceFloat(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   assert(min <= num && num <= max);
   return num;
}


void Advance::advance(Bird& bird)
{
   setDrag(bird);
   setInertia(bird);
   setGravity(bird);
   setErratic(bird);
   checkBounds(bird);
};


/***************************************************************/
/*                            SET DRAG                         */
/***************************************************************/
void Advance::setDrag(Bird& bird)
{
   return; // inheritted as null
};

/***************************************************************/
/*                           SET INERTIA                       */
/***************************************************************/
void Advance::setInertia(Bird& bird)
{
   bird.adjustPosition(bird.getVelocity());
};

/***************************************************************/
/*                           SET GRAVITY                       */
/***************************************************************/
void Advance::setGravity(Bird& bird)
{
   return; // inheritted as null
};

/***************************************************************/
/*                           SET ERRATIC                       */
/***************************************************************/
void Advance::setErratic(Bird& bird)
{
   return; // inheritted as null
};

/***************************************************************/
/*                           CHECK BOUNDS                      */
/***************************************************************/
void Advance::checkBounds(Bird& bird)
{
   if (bird.isOutOfBounds())
   {
      bird.kill();
      int points = bird.getPoints();
      points *= -1;
      bird.setPoints(points); // points go negative when it is missed!
   }
};



/*********************************************
 * STANDARD SET DRAG
 * Standards have a small amount of Drag
 *********************************************/
void StandardAdvance::setDrag(Bird& bird)
{
   // small amount of drag
   bird.adjustVelocity(0.995);
}

/*********************************************
 * FLOATER SET DRAG
 * Floaters have a large amount of drag
 *********************************************/
void FloaterAdvance::setDrag(Bird& bird)
{
   // large amount of drag
   bird.adjustVelocity(0.990);
}

/*********************************************
 * FLOATER SET GRAVITY
 * Floaters have the ability to float
 *********************************************/
void FloaterAdvance::setGravity(Bird& bird)
{
   // Get velocity, adjust it
      Velocity v = bird.getVelocity();
      // Gravity
      v.addDy(0.05);
      // Adjust position
      bird.adjustPosition(v);
      // Apply gravity to Bird's velocity
      bird.setVelocity(v);
}

/*********************************************
 * CRAZY SET ERRATIC
 * How the crazy bird moves, every half a second it changes direciton
 *********************************************/
void CrazyAdvance::setErratic(Bird& bird)
{
   // erratic turns eery half a second or so
   Velocity v = bird.getVelocity();
   if (randomAdvanceInt(0, 15) == 0)
   {
      v.addDy(randomAdvanceFloat(-1.5, 1.5));
      v.addDx(randomAdvanceFloat(-1.5, 1.5));
      bird.setVelocity(v);
   }
}

/*********************************************
 * SINKER SET GRAVITY
 * How the sinker bird moves, no drag but gravity
 *********************************************/
void SinkerAdvance::setGravity(Bird& bird)
{
   // gravity
   Velocity v = bird.getVelocity();
   v.addDy(-0.07);
   bird.setVelocity(v);
}
