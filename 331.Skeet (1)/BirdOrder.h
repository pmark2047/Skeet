//
//  BirdOrder.h
//  Skeet
//
//  Created by Peyton Markus on 3/14/26.
//

#pragma once
#include "bird.h"

/*************************************
 * BIRD ORDER
 * Orders everything that can be shot
 ************************************/
class BirdOrder
{
private:
   Bird* pBird;
public:
   BirdOrder() { }
   virtual ~BirdOrder() { }
   
   virtual void execute() = 0;
};


/*************************************
 * BIRD DRAW
 * Draws everything that can be shot
 ************************************/
class BirdDraw : public BirdOrder
{
private:
   Bird* pBird;
public:
   BirdDraw(Bird* pBird) { this->pBird = pBird; }
   virtual ~BirdDraw() { }
   
   virtual void execute() override { pBird->draw(); }
};

/*************************************
 * BIRD ADVANCE
 * Moves everything that can be shot
 ************************************/
class BirdAdvance : public BirdOrder
{
private:
   Bird* pBird;
public:
   BirdAdvance(Bird* pBird) { this->pBird = pBird; }
   virtual ~BirdAdvance() { }
   
   virtual void execute() override { pBird->advance(); }
};
