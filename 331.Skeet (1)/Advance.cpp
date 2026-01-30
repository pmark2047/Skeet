//
//  Advance.cpp
//  Lab03
//
//  Created by Elijah Dodge on 1/28/26.
//

#include <cassert>
#include "Advance.hpp"
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

/*********************************************
 * INERTIA ADVANCE
 * How a standard bird moves - inertia and drag
 *********************************************/
void Inertia::advance(Bird& bird)
{
   // Adjust velocity
   bird.adjustVolocity(0.995);
   
   // Adjust position
   bird.adjustPosition(bird.getVelocity());
   
   // Check if Bird is out of bounds
   if (bird.isOutOfBounds())
   {
      bird.kill();
      int points = bird.getPoints();
      points *= -1;
      bird.setPoints(points);
   }
}

/*********************************************
 * GRAVITY ADVANCE
 * How the sinker bird moves, no drag but gravity
 *********************************************/
void Gravity::advance(Bird& bird)
{
   // Get velocity, adjust it
   Velocity v = bird.getVelocity();
   
   // Gravity
   v.addDy(-0.07);
   
   // Adjust position
   bird.adjustPosition(v);
   
   // Apply gravity to Bird's velocity
   bird.setVolocity(v);
   
   // Check if Bird is out of bounds
   if (bird.isOutOfBounds())
   {
      bird.kill();
      int points = bird.getPoints();
      points *= -1;
      bird.setPoints(points);
   }
}

/*********************************************
 * BOUYANCY ADVANCE
 * How the floating bird moves: strong drag and anti-gravity
 *********************************************/
void Buoyancy::advance(Bird& bird)
{
   // Get velocity, adjust it
   Velocity v = bird.getVelocity();
   
   v *= 0.990;
   
   // Adjust position
   bird.adjustPosition(v);
   
   // Apply anti-gravity to Bird's velocity
   v.addDy(0.05);
   bird.setVolocity(v);
   
   // Check if Bird is out of bounds
   if (bird.isOutOfBounds())
   {
      bird.kill();
      int points = bird.getPoints();
      points *= -1;
      bird.setPoints(points);
   }
}

/*********************************************
 * CHAOS ADVANCE
 * How the crazy bird moves, every half a second it changes direciton
 *********************************************/
void Chaos::advance(Bird& bird)
{
   // Get velocity
   Velocity v = bird.getVelocity();
   
   // Erratic turns eery half a second or so
   if (randomAdvanceInt(0, 15) == 0)
   {
      v.addDy(randomAdvanceFloat(-1.5, 1.5));
      v.addDx(randomAdvanceFloat(-1.5, 1.5));
   }
   
   // Inertia
   bird.adjustPosition(v);
   
   // Make sure we set Bird's velocity
   bird.setVolocity(v);
   
   // Check if Bird is out of bounds
   if (bird.isOutOfBounds())
   {
      bird.kill();
      int points = bird.getPoints();
      points *= -1;
      bird.setPoints(points);
   }
}
