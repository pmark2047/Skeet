/***********************************************************************
 * Header File:
 *    GUN
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The gun at the bottom of the screen
 ************************************************************************/

#pragma once
#include "position.h"

/*********************************************
 * GUN
 * The gun at the bottom of the screen
 *********************************************/
class Gun
{
public:
   Gun(const Position & pt) : angle(0.78 /* 45 degrees */), pt(pt) {}  // 45 degrees initially
   void display() const;
   void interact(int clockwise, int counterclockwise);
   double getAngle() const { return angle; }
   
private:
   double angle;
   Position pt;
};


/************************************************************************
 * GUN LOGIC
 * The logic of the gun, such as how it moves.
 * 
 ************************************************************************/
class GunLogic
{
   class GunStorage;
public:
   void interact(GunStorage& storage,
      int clockwise,
      int counterclockwise);
};


/************************************************************************
 * GUN INTERFACE
 * The interface of the gun, such as how it interacts with the user.
 * 
 ************************************************************************/
class GunInterface
{
   class GunLogic;
public:
   void draw(const GunStorage& storage) const;
};


/************************************************************************
 * GUN STORAGE
 * The storage of the gun, such as how it stores its state.
 * 
 ************************************************************************/
class GunStorage
{
public:
   GunStorage(const Position& pt)
      : angle(0.78), pt(pt) {
   }

   double getAngle() const { return angle; }
   void setAngle(double a) { angle = a; }

   const Position& getPosition() const { return pt; }

private:
   double angle;
   Position pt;
};
