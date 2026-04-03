/***********************************************************************
 * Header File:
 *    Bullet
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that kills other things
 ************************************************************************/

#pragma once
#include "position.h"
#include "effect.h"
#include "ogstream.h"   
#include <list>
#include <cassert>

/*********************************************
 * BULLET
 *********************************************/
class Bullet
{
protected:
   static Position dimensions;   
   Position pt;                  
   Velocity v;                
   double radius;             
   bool dead;                 
   int value;                 

public:
   Bullet(double angle = 0.0, double speed = 30.0, double radius = 5.0, int value = 1);
   
   void kill()                   { dead = true; }
   void setValue(int newValue)   { value = newValue; }

   bool isDead()           const { return dead;   }
   Position getPosition()  const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getValue()          const { return value;  }

   virtual void death(std::list<Bullet *> & bullets) {}
   virtual void output(ogstream & gout) = 0;       
   virtual void input(bool isUp, bool isDown, bool isB) {}
   virtual void move(std::list<Effect*> &effects);

protected:
   bool isOutOfBounds() const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }
   void drawLine(const Position& begin, const Position& end,
                 double red = 1.0, double green = 1.0, double blue = 1.0) const;

   void drawDot(const Position& point, double radius = 2.0,
                double red = 1.0, double green = 1.0, double blue = 1.0) const;
   int    random(int    min, int    max);
   double random(double min, double max);
};

/*********************
 * PELLET
 **********************/
class Pellet : public Bullet
{
public:
   Pellet(double angle, double speed = 15.0) : Bullet(angle, speed, 1.0, 1) {}
   void output(ogstream & gout);     
};

/*********************
 * BOMB
 **********************/
class Bomb : public Bullet
{
private:
   int timeToDie;
public:
   Bomb(double angle, double speed = 10.0) : Bullet(angle, speed, 4.0, 4), timeToDie(60) {}
   void output(ogstream & gout);     
   void move(std::list<Effect*> & effects);
   void death(std::list<Bullet *> & bullets);
};

/*********************
 * SHRAPNEL
 **********************/
class Shrapnel : public Bullet
{
private:
   int timeToDie;
public:
   Shrapnel(const Bomb & bomb)
   {
      timeToDie = random(5, 15);
      v.set(random(0.0, 6.2), random(10.0, 15.0));
      pt = bomb.getPosition();
      value = 0;
      radius = 3.0;
   }
   void output(ogstream & gout);    
   void move(std::list<Effect*> & effects);
};

/*********************
 * MISSILE
 **********************/
class Missile : public Bullet
{
public:
   Missile(double angle, double speed = 10.0) : Bullet(angle, speed, 1.0, 3) {}
   void output(ogstream & gout);    
   void input(bool isUp, bool isDown, bool isB)
   {
      if (isUp) v.turn(0.04);
      if (isDown) v.turn(-0.04);
   }
   void move(std::list<Effect*> & effects);
};
