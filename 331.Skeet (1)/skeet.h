/***********************************************************************
 * Header File:
 *    SKEET
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The game class
 ************************************************************************/

#pragma once

#include "position.h"
#include "uiInteract.h"
#include "bird.h"
#include "bullet.h"
#include "effect.h"
#include "gun.h"
#include "time.h"
#include "score.h"
#include "points.h"

#include <list>

/*************************************************************************
 * Skeet
 * The game class
 *************************************************************************/
class Skeet
{
public:
    // handle all user input
    virtual void interact(const UserInput& ui) = 0;

    // move the gameplay by one unit of time
    virtual void animate() = 0;

    // output everything on the screen
    virtual void drawLevel() const = 0;    // output the game
    virtual void drawStatus() const = 0;    // output the status information

    // is the game currently playing right now?
    virtual bool isPlaying() const = 0;
};

/*************************************************************************
 * Real Skeet
 * The REAL game class
 *************************************************************************/
class RealSkeet : public Skeet
{
public:
    RealSkeet(Position & dimensions) : dimensions(dimensions),
   gun(Position(800.0, 0.0)), time(), score(), hitRatio(), bullseye(false) {}

    // handle all user input
    void interact(const UserInput& ui) override;

    // move the gameplay by one unit of time
    void animate() override;

    // output everything on the screen
    void drawLevel() const override;    // output the game
    void drawStatus() const override;    // output the status information

    // is the game currently playing right now?
    bool isPlaying() const override { return time.isPlaying();  }
private:
    // generate new birds
    void spawn();                  
    void drawBackground(double redBack, double greenBack, double blueBack) const;
    void drawTimer(double percent,
                   double redFore, double greenFore, double blueFore,
                   double redBack, double greenBack, double blueBack) const;
    void drawBullseye(double angle) const;

    Gun gun;                       // the gun
    std::list<Bird*> birds;        // all the shootable birds
    std::list<Bullet*> bullets;    // the bullets
    std::list<Effect*> effects;    // the fragments of a dead bird.
    std::list<Points>  points;     // point values;
    Time time;                     // how many frames have transpired since the beginning
    Score score;                   // the player's score
    HitRatio hitRatio;             // the hit ratio for the birds
    Position dimensions;           // size of the screen
    bool bullseye;
};

/*************************************************************************
 * Proxy Skeet
 * The FAKE game class
 *************************************************************************/
class ProxySkeet : public Skeet
{
public:
   ProxySkeet(Position & dimensions) { pRealSkeet = new RealSkeet(dimensions); }

    // handle all user input
    void interact(const UserInput& ui) override;

    // move the gameplay by one unit of time
    void animate() override;

    // output everything on the screen
    void drawLevel() const override;    // output the game
    void drawStatus() const override;    // output the status information

    // is the game currently playing right now?
   bool isPlaying() const override { return pRealSkeet->isPlaying(); }
private:
   Skeet * pRealSkeet;
};
