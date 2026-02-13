//
//  colleague.hpp
//  Lab03
//
//  Created by Elijah Dodge on 2/12/26.
//

#pragma once
#include "mediator.hpp"
class Bird;

class AbstractColleague
{
protected:
   Mediator* mediator;
   
public:
   void enroll(Mediator* mediator);
   void unenroll(Mediator* mediator);
   virtual void notify(enum message msg) = 0;
};

class BirdColleague : AbstractColleague
{
private:
   bool status();
   
public:
   void notify(enum message msg) override;
   void wentOutOfBounds();
   void wasShot();
   
};

class BulletColleague : AbstractColleague
{
   
};

class ScoreColleague : AbstractColleague
{
   
};

class HitRatioColleague : AbstractColleague
{
   
};
