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
class SkeetInterface
{
   class SkeetLogic;
public:
    SkeetInterface(Position & dimensions) : dimensions(dimensions),
        gun(Position(800.0, 0.0)), time(), score(), hitRatio(), bullseye(false) {}

    // output everything on the screen
    void drawLevel()  const;    // output the game
    void drawStatus() const;    // output the status information
   
    void playSkeet(const UserInput& ui);
    
private:
   SkeetLogic skeetLogic;
   
   GunInterface gunInterface;
   BirdInterface birdInterface;
   BulletInterface bulletInterface;
   EffectInterface effectInterface;
   PointsInterface pointsInterface;
   
   
   void drawBackground(double redBack, double greenBack, double blueBack) const;
   void drawTimer(double percent,
                double redFore, double greenFore, double blueFore,
                double redBack, double greenBack, double blueBack) const;
   void drawBullseye(double angle) const;

    
};


class SkeetLogic
{
   class SkeetStorage;
public:
   SkeetLogic() {}
   
   void playSkeet(const UserInput& ui);
   
   // handle all user input
   void interact(const UserInput& ui);
   
   // move the gameplay by one unit of time
   void animate();

private:
   GunLogic gunLogic;
   birdLogic BirdLogic;
   bulletLogic BulletLogic;
   effectLogic EffectLogic;
   pointsLogic PointsLogic;
   scoreLogic ScoreLogic;
   hitRatioLogic HitRatioLogic;
   
   SkeetStorage skeetStorage;

   // generate new birds
   void spawn();
};


class SkeetStorage
{
public:
   // is the game currently playing right now?
   bool isPlaying() const { return time.isPlaying();  }
   void incrementTime() { time++; }
   Time getTimeStatus() { return time.isStatus(); }
   void clearLists();
   
// private:
   GunStorage gunStorage;                       // the gun
   std::list<BirdStorage*> birds;        // all the shootable birds
   std::list<BulletStorage*> bullets;    // the bullets
   std::list<EffectStorage*> effects;    // the fragments of a dead bird.
   std::list<PointsStorage>  points;     // point values;
   Time time;                     // how many frames have transpired since the beginning
   ScoreStorage score;                   // the player's score
   HitRatioStorage hitRatio;             // the hit ratio for the birds
   PositionStorage dimensions;           // size of the screen
   bool bullseye;
};
