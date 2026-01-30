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

class Bird;

/**********************
 * ADVANCE (Strategy)
 **********************/
class Advance
{
public:
   virtual ~Advance() = default;
   virtual void advance(Bird& bird) = 0;
};

/*********************************************
 * STANDARD ADVANCE
 * Movement for Standard birds
 *********************************************/
class StandardAdvance : public Advance
{
public:
   void advance(Bird& bird) override;
};

/*********************************************
 * FLOATER ADVANCE
 * Movement for Floater birds
 *********************************************/
class FloaterAdvance : public Advance
{
public:
   void advance(Bird& bird) override;
};

/*********************************************
 * SINKER ADVANCE
 * Movement for Sinker birds
 *********************************************/
class SinkerAdvance : public Advance
{
public:
   void advance(Bird& bird) override;
};

/*********************************************
 * CRAZY ADVANCE
 * Movement for Crazy birds
 *********************************************/
class CrazyAdvance : public Advance
{
public:
   void advance(Bird& bird) override;
};

