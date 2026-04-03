/***********************************************************************
 * Header File:
 *    Bird : Everything that can be shot
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that moves across the screen to be shot
 ************************************************************************/

#pragma once
#include "position.h"
#include "ogstream.h"  

/**********************
 * BIRD
 * Everything that can be shot
 **********************/
class Bird
{
protected:
   static Position dimensions; // size of the screen
   Position pt;                // position of the flyer
   Velocity v;                 // velocity of the flyer
   double radius;              // the size (radius) of the flyer
   bool dead;                  // is this flyer dead?
   int points;                 // how many points is this worth?
   
public:
   Bird() : dead(false), points(0), radius(1.0) { }
   
   // setters
   void operator=(const Position & rhs) { pt = rhs; }
   void operator=(const Velocity & rhs) { v = rhs; }
   void kill()                          { dead = true; }
   void setPoints(int pts)              { points = pts; }

   // getters
   bool isDead() const           { return dead; }
   Position getPosition() const  { return pt; }
   Velocity getVelocity() const  { return v; }
   double getRadius() const      { return radius; }
   int getPoints() const         { return points; }
   bool isOutOfBounds() const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }

   // special functions
   virtual void draw(ogstream & gout) = 0;  
   virtual void advance() = 0;
};

/*********************************************
 * STANDARD
 *********************************************/
class Standard : public Bird
{
public:
    Standard(double radius = 25.0, double speed = 5.0, int points = 10);
    void draw(ogstream & gout);
    void advance();
};

/*********************************************
 * FLOATER
 *********************************************/
class Floater : public Bird
{
public:
    Floater(double radius = 30.0, double speed = 5.0, int points = 15);
    void draw(ogstream & gout);
    void advance();
};

/*********************************************
 * CRAZY
 *********************************************/
class Crazy : public Bird
{
public:
    Crazy(double radius = 30.0, double speed = 4.5, int points = 30);
    void draw(ogstream & gout);
    void advance();
};

/*********************************************
 * SINKER
 *********************************************/
class Sinker : public Bird
{
public:
    Sinker(double radius = 30.0, double speed = 4.5, int points = 20);
    void draw(ogstream & gout);
    void advance();
};
