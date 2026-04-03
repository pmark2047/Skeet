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
#include "ogstream.h"

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
    Effect(const Position & pt) : pt(pt), age(1.0) {}
    
    virtual ~Effect() {}
    virtual void fly() = 0;
    virtual void render(ogstream & gout) const = 0;
    bool isDead() const { return age <= 0.0; }
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
    void render(ogstream & gout) const override;
    
    // move it forward with regards to inertia. Let it age
    void fly() override;
};

/**********************
 * STREEK
 * Stuff that trails off the back of shrapnel
 **********************/
class Streek : public Effect
{
private:
   Position ptEnd;
   Velocity v;
public:
    // create a fragment based on the velocity and position of the bullet
    Streek(const Position & pt, Velocity v);
    
    // draw it
    void render(ogstream & gout) const override;
    
    // move it forward with regards to inertia. Let it age
    void fly() override;
};

/**********************
 * EXHAUST
 * Stuff that comes out the back of a missile when in flight
 **********************/
class Exhaust : public Effect
{
private:
   Position ptEnd;
   Velocity v;
public:
    // create a fragment based on the velocity and position of the bullet
    Exhaust(const Position & pt, Velocity v);
    
    // draw it
    void render(ogstream & gout) const override;
    
    // move it forward with regards to inertia. Let it age
    void fly() override;
};
