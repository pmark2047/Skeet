/***********************************************************************
 * Source File:
 *    Bullet
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that kills other things
 ************************************************************************/

#include "bullet.h"

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>
#include <GLUT/glut.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif

#ifdef __linux__
#include <GL/gl.h>
#include <GL/glut.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif

/*********************************************
 * BULLET constructor
 *********************************************/
Bullet::Bullet(double angle, double speed, double radius, int value) :
   dead(false), radius(radius), value(value)
{
   pt.setX(dimensions.getX() - 1.0);
   pt.setY(1.0);
   assert(pt.getX() > 100.0);

   v.setDx(-speed * cos(angle));
   v.setDy(speed * sin(angle));
   assert(v.getDx() <= 0.0);
   assert(v.getDy() >= 0.0);
}

/*********************************************
 * BOMB DEATH
 *********************************************/
void Bomb::death(std::list<Bullet*>& bullets)
{
   for (int i = 0; i < 20; i++)
      bullets.push_back(new Shrapnel(*this));
}

/***************************************************************
 *                             MOVE
 ***************************************************************/

/*********************************************
 * BULLET MOVE
 *********************************************/
void Bullet::move(std::list<Effect*> & effects)
{
   pt.add(v);
   if (isOutOfBounds())
      kill();
}

/*********************************************
 * BOMB MOVE
 *********************************************/
void Bomb::move(std::list<Effect*> & effects)
{
    timeToDie--;
    if (!timeToDie)
        kill();

    Bullet::move(effects);
}

/*********************************************
 * MISSILE MOVE
 *********************************************/
void Missile::move(std::list<Effect*> & effects)
{
   effects.push_back(new Exhaust(pt, v));
   Bullet::move(effects);
}

/*********************************************
 * SHRAPNEL MOVE
 *********************************************/
void Shrapnel::move(std::list<Effect*> & effects)
{
    timeToDie--;
    if (!timeToDie)
        kill();

    effects.push_back(new Streek(pt, v));
    Bullet::move(effects);
}

/***************************************************************
 *                             OUTPUT
 ***************************************************************/

/*********************************************
 * PELLET OUTPUT
 *********************************************/
void Pellet::output(ogstream & gout)
{
   if (!isDead())
      gout.drawDot(pt);
}

/*********************************************
 * BOMB OUTPUT
 *********************************************/
void Bomb::output(ogstream & gout)
{
   if (!isDead())
   {
       gout.drawDot(pt);
       gout.drawDot(pt);
       gout.drawDot(pt);
       gout.drawDot(pt);
   }
}

/*********************************************
 * SHRAPNEL OUTPUT
 *********************************************/
void Shrapnel::output(ogstream & gout)
{
    if (!isDead())
        gout.drawDot(pt);
}

/*********************************************
 * MISSILE OUTPUT
 *********************************************/
void Missile::output(ogstream & gout)
{
    if (!isDead())
    {
        Position ptNext(pt);
        ptNext.add(v);
        gout.drawLine(pt, ptNext);
        gout.drawDot(pt);
    }
}

/***************************************************************
 *                             MISC.
 ***************************************************************/

int Bullet::random(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);
   return num;
}

double Bullet::random(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   assert(min <= num && num <= max);
   return num;
}
