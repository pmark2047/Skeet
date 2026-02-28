/***********************************************************************
 * Header File:
 *    Fragment : Pieces that fly off a dead bird
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Pieces that fly off a dead bird
 ************************************************************************/

#pragma once
#include "position.h"

/**********************
 * Effect: stuff that is not interactive
 **********************/
class Effect
{
protected:
    Position pt;      // location of the effect
    double age;    // 1.0 = new, 0.0 = dead
public:
    // create a fragment based on the velocity and position of the bullet
    Effect(const Position & pt) : pt(pt), age(0.5) {}
    
    // draw it
    virtual void render() const = 0;
    
    // move it forward with regards to inertia. Let it age
    virtual void fly() = 0;
    
    // it is dead when age goes to 0.0
    bool isDead() const { return age <= 0.0; }

    // Gets the position
    Position getPosition() const { return pt; }
};

/**********************
 * FRAGMENT
 * Pieces that fly off a dead bird
 **********************/
class Fragment : public Effect
{
private:
   Velocity v;    // direction the fragment is flying
   double size;   // size of the fragment
public:
    // create a fragment based on the velocity and position of the bullet
    Fragment(const Position & pt, const Velocity & v);
    
    // draw it
    void render() const;
    
    // move it forward with regards to inertia. Let it age
    void fly();
};

/**********************
 * STREEK
 * Stuff that trails off the back of shrapnel
 **********************/
class Streek : public Effect
{
private:
   Position ptEnd;
public:
    // create a fragment based on the velocity and position of the bullet
    Streek(const Position & pt, Velocity v);
    
    // draw it
    void render() const;
    
    // move it forward with regards to inertia. Let it age
    void fly();
};

/**********************
 * EXHAUST
 * Stuff that comes out the back of a missile when in flight
 **********************/
class Exhaust : public Effect
{
private:
   Position ptEnd;
public:
    // create a fragment based on the velocity and position of the bullet
    Exhaust(const Position & pt, Velocity v);
    
    // draw it
    void render() const;
    
    // move it forward with regards to inertia. Let it age
    void fly();
};



//New Implementations of separated logic, interface, and storage for Effect

class EffectStorage
{
public:
   EffectStorage(const Position& pt)
      : pt(pt), age(0.5) {
   }

   bool isDead() const { return age <= 0.0; }

   Position pt;
   double age;
};

class FragmentStorage : public EffectStorage
{
public:
   FragmentStorage(const Position& pt, const Velocity& baseVelocity);

   Velocity v;
   double size;
};

class FragmentLogic
{
public:
   void fly(FragmentStorage& storage);
};

class FragmentInterface
{
public:
   void render(const FragmentStorage& storage) const;
};

class Fragment : public Effect
{
public:
   Fragment(const Position& pt, const Velocity& v)
      : storage(pt, v) {}

   void render() const override
   {
      interface.render(storage);
   }

   void fly() override
   {
      logic.fly(storage);
   }

private:
   FragmentStorage storage;
   FragmentLogic logic;
   FragmentInterface interface;
};