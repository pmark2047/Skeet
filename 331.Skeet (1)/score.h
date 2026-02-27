/***********************************************************************
 * Header File:
 *    Score
 * Author:
 *    Br. Helfrich
 * Summary:
 *    How well the player is doing
 ************************************************************************/

#pragma once
#include <string>

/**********************
 * STATUS LOGIC
 * How well the player is doing
 **********************/
class StatusLogic
{
public:
   StatusLogic() {}
   virtual void adjust(int value) = 0;
};

/**********************
 * STATUS STORAGE
 * How well the player is doing
 **********************/
class StatusStorage
{
public:
    StatusStorage() {}
    virtual std::string getText() const = 0;
    virtual void reset() = 0;
};


/**********************
 * SCORE LOGIC
 * Points earned vs lost
 **********************/
class ScoreLogic : public StatusLogic
{
public:
    ScoreLogic() { }
    void adjust(int value) { points += value; }
};

/**********************
 * SCORE STORAGE
 * Points earned vs lost
 **********************/
class ScoreStorage : public StatusStorage
{
public:
    ScoreStorage() { reset(); }
    std::string getText() const;
    void reset() { points = 0; }
private:
    int points;
};

/**********************
 * HIT RATIO LOGIC
 * Bird hit ratio
 **********************/
class HitRatioLogic : public StatusLogic
{
public:
    HitRatioLogic()  { }
    void adjust(int value);
};

/**********************
 * HIT RATIO STORAGE
 * Bird hit ratio
 **********************/
class HitRatioStorage : public StatusStorage
{
public:
    HitRatioStorage()  { reset(); }
    std::string getText() const;
    void reset() { numKilled = numMissed = 0; }
private:
    int numKilled;
    int numMissed;
};
