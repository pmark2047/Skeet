/***********************************************************************
 * Source File:
 *    Score
 * Author:
 *    Br. Helfrich
 * Summary:
 *    How well the player is doing
 ************************************************************************/

#include "score.h"
#include <sstream>
using namespace std;

/************************
 * SCORE GET TEXT
 * Get the status text
 ************************/
string Score::getText() const
{
    ostringstream sout;
    sout << "Score:  " << points;
    return sout.str();
}

/************************
 * HIT RATIO  GET TEXT
 * Get the status text
 ************************/
string HitRatio::getText() const
{
    ostringstream sout;
    sout << "Birds:   ";
    
    // compute the percentage when possible
    if (numMissed + numKilled)
        sout << (numKilled * 100 / (numMissed + numKilled)) << "%";
    else
        sout << "--";

    return sout.str();
}

/************************
 * HIT RATIO  ADJUST
 * Adjust the score for a bird hit (positive) or missed (negative)
 ************************/
void HitRatio::adjust(int value)
{
    if (value > 0)
        numKilled++;
    else if (value < 0)
        numMissed++;
}

/************************
 * SCORE UPDATE
 * Update the score based on the event
 ************************/
void Score::update(EventType event, int value)
{
   if (event == SCORE_CHANGE)
      adjust(value);
}

/************************
 * HIT RATIO UPDATE
 * Update the hit ratio based on the event
 ************************/
void HitRatio::update(EventType event, int value)
{
   if (event == BIRD_HIT)
      adjust(1);
   else if (event == BIRD_MISSED)
      adjust(-1);
}
