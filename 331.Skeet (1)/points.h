/***********************************************************************
 * Header File:
 *    Points : Points graphic drawn on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Inert point values on the screen.
 ************************************************************************/


#pragma once

#include "position.h"
/*
 *********************************************
  * POINTS
  * Points graphic drawn on the screen
  *********************************************
class Points
{
public:
   Points(const Position& pt, int value);
   void show() const;
   void update();
   bool isDead() const {return age <= 0.0; }
private:
   Position pt;
   Velocity v;
   int value;
   float age;
};
*/



/*********************************************
 * POINTS INTERFACE
 * Points graphic drawn on the screen
 *********************************************/
class PointsInterface
{
public:
  PointsInterface();
  void show(Position pt, int value, float age) const;
};

/*********************************************
 * POINTS LOGIC
 * Points graphic drawn on the screen
 *********************************************/
class PointsLogic
{
public:
  PointsLogic();
  void update(Position pt, Velocity v, float age);
};

/*********************************************
 * POINTS STORAGE
 * Points graphic drawn on the screen
 *********************************************/
class PointsStorage
{
public:
  PointsStorage(const Position& pt, int value);
  bool isDead() const {return age <= 0.0; }
private:
  Position pt;
  Velocity v;
  int value;
  float age;
};
