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

// Forward Declarations so the compiler can chill out
class BirdLogic;
class BirdStorage;
/*
 
 
 * BIRD
 * Everything that can be shot
class Bird
{
protected:
   static Position dimensions; // size of the screen
   Position pt;                  // position of the flyer
   Velocity v;                // velocity of the flyer
   double radius;             // the size (radius) of the flyer
   bool dead;                 // is this flyer dead?
   int points;                // how many points is this worth?
   
public:
   Bird() : dead(false), points(0), radius(1.0) { }
   
   // setters
   void operator=(const Position    & rhs) { pt = rhs;    }
   void operator=(const Velocity & rhs) { v = rhs;     }
   void kill()                          { dead = true; }
   void setPoints(int pts)              { points = pts;}

   // getters
   bool isDead()           const { return dead;   }
   Position getPosition()     const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getPoints() const { return points; }
   bool isOutOfBounds() const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }

   // special functions
   virtual void draw() = 0;
   virtual void advance() = 0;
};
 
 
*/

enum BIRDTYPE { STANDARD, CRAZY, FLOATER, SINKER };


/**********************
 * BIRD INTERFACE
 * Interface of everything that can be shot
 **********************/
class BirdInterface
{
public:
   BirdInterface() { };
   virtual void draw(Position pt, double radius, bool dead) = 0;
};

/**********************
 * BIRD LOGIC
 * Logic of everything that can be shot
 **********************/
class BirdLogic
{
public:
   BirdLogic() { };
   
   // setters
   void kill(bool dead)                          { dead = true; }
   bool isOutOfBounds(Position pt, Position dimensions, double radius) const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }
   virtual void advance(Velocity v, Position pt, Position dimensions, double radius, int points, bool dead) = 0;
};

/**********************
 * BIRD STORAGE
 * Storage of everything that can be shot
 **********************/
class BirdStorage
{
protected:
   static Position dimensions; // size of the screen
   Position pt;                  // position of the flyer
   Velocity v;                // velocity of the flyer
   double radius;             // the size (radius) of the flyer
   bool dead;                 // is this flyer dead?
   int points;                // how many points is this worth?
   
public:
   BirdStorage() : dead(false), points(0), radius(1.0) { }
   
   // setters
   void operator=(const Position    & rhs) { pt = rhs;    }
   void operator=(const Velocity & rhs) { v = rhs;     }
   void setPoints(int pts)              { points = pts;}
   void setVelocity(Velocity v) { this->v = v;     }
   void setPoision(Position pt) { this->pt = pt;   }
   void addInertia(Velocity v)  { this->pt.add(v); }

   // getters
   bool isDead()           const { return dead;   }
   Position getPosition()  const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getPoints() const { return points; }
   virtual BIRDTYPE getType();
};



/*********************************************
 * STANDARD INTERFACE
 * A standard bird: slows down, flies in a straight line
 *********************************************/
class StandardInterface : public BirdInterface
{
public:
    StandardInterface();
    void draw(Position pt, double radius, bool dead);
};

/*********************************************
 * STANDARD LOGIC
 * A standard bird: slows down, flies in a straight line
 *********************************************/
class StandardLogic : public BirdLogic
{
public:
    StandardLogic();
    void advance(Velocity v, Position pt, Position dimensions, double radius, int points, bool dead);
};

/*********************************************
 * STANDARD STORAGE
 * A standard bird: slows down, flies in a straight line
 *********************************************/
class StandardStorage : public BirdStorage
{
public:
    StandardStorage(double radius = 25.0, double speed = 5.0, int points = 10);
    BIRDTYPE getType()
    {
       BIRDTYPE type = STANDARD;
       return type;
    }
};



/*********************************************
 * FLOATER INTERFACE
 * A bird that floats like a balloon: flies up and really slows down
 *********************************************/
class FloaterInterface : public BirdInterface
{
public:
    FloaterInterface();
    void draw(Position pt, double radius, bool dead);
};

/*********************************************
 * FLOATER LOGIC
 * A bird that floats like a balloon: flies up and really slows down
 *********************************************/
class FloaterLogic : public BirdLogic
{
public:
    FloaterLogic();
    void advance(Velocity v, Position pt, Position dimensions, double radius, int points, bool dead);
};

/*********************************************
 * FLOATER STORAGE
 * A bird that floats like a balloon: flies up and really slows down
 *********************************************/
class FloaterStorage : public BirdStorage
{
public:
    FloaterStorage(double radius = 30.0, double speed = 5.0, int points = 15);
   BIRDTYPE getType()
   {
      BIRDTYPE type = FLOATER;
      return type;
   }
};



/*********************************************
 * CRAZY INTERFACE
 * A crazy flying object: randomly changes direction
 *********************************************/
class CrazyInterface : public BirdInterface
{
public:
    CrazyInterface();
    void draw(Position position, double radius, bool dead);
};

/*********************************************
 * CRAZY LOGIC
 * A crazy flying object: randomly changes direction
 *********************************************/
class CrazyLogic : public BirdLogic
{
public:
    CrazyLogic();
    void advance(Velocity v, Position pt, Position dimensions, double radius, int points, bool dead);
};

/*********************************************
 * CRAZY STORAGE
 * A crazy flying object: randomly changes direction
 *********************************************/
class CrazyStorage : public BirdStorage
{
public:
    CrazyStorage(double radius = 30.0, double speed = 4.5, int points = 30);
   BIRDTYPE getType()
   {
      BIRDTYPE type = CRAZY;
      return type;
   }
};



/*********************************************
 * SINKER INTERFACE
 * A sinker bird: honors gravity
 *********************************************/
class SinkerInterface : public BirdInterface
{
public:
    SinkerInterface();
    void draw(Position position, double radius, bool dead);
};

/*********************************************
 * SINKER LOGIC
 * A sinker bird: honors gravity
 *********************************************/
class SinkerLogic : public BirdLogic
{
public:
    SinkerLogic();
    void advance(Velocity v, Position pt, Position dimensions, double radius, int points, bool dead);
};

/*********************************************
 * SINKER STORAGE
 * A sinker bird: honors gravity
 *********************************************/
class SinkerStorage : public BirdStorage
{
public:
    SinkerStorage(double radius = 30.0, double speed = 4.5, int points = 20);
   BIRDTYPE getType()
   {
      BIRDTYPE type = SINKER;
      return type;
   }
};
