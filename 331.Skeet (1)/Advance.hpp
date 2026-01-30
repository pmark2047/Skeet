/***********************************************************************
 * Source File:
 *    Advance : How a Bird moves
 * Author:
 *    Elijah Dodge, Noah McSheehy
 * Summary:
 *    How a bird advances across the screen.
 ************************************************************************/


#pragma once
#include "position.h"
//#include "bird.h"

class Bird;

class Advance
{
public:
   virtual void advance(Bird& bird) = 0;
};

/*********************************************
 * INERTIA ADVANCE CONCRETE STRATEGY
 * How a standard bird moves - inertia and drag
 *********************************************/
class Inertia : public Advance
{
public:
   void advance(Bird& bird) override;
};

/*********************************************
 * GRAVITY ADVANCE CONCRETE STRATEGY
 * How the sinker bird moves, no drag but gravity
 *********************************************/
class Gravity : public Advance
{
public:
   void advance(Bird& bird) override;
};

/*********************************************
 * BOUYANCY ADVANCE CONCRETE STRATEGY
 * How the floating bird moves: strong drag and anti-gravity
 *********************************************/
class Buoyancy : public Advance
{
public:
   void advance(Bird& bird) override;
};

/*********************************************
 * CHAOS ADVANCE CONCRETE STRATEGY
 * How the crazy bird moves, every half a second it changes direciton
 *********************************************/
class Chaos : public Advance
{
public:
   void advance(Bird& bird) override;
};
