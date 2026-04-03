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
#include "ogstream.h"

/*********************************************
 * GUN
 * The gun at the bottom of the screen
 *********************************************/
class Gun
{
public:
   Gun(const Position & pt = Postion(0,0)) : angle(0.0) pt(pt) {} 
   void display(ogstream & gout) const;
   void interact(int clockwise, int counterclockwise);
   double getAngle() const { return angle; }
   
private:
   double angle;
   Position pt;
};
