//
//  levelHandler.cpp
//  Lab03
//
//  Created by Peyton Markus on 2/14/26.
//

#include "levelHandler.h"


/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int random(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}


/******************************************************************
 * LEVEL ONE HANDLER :: HANDLE LEVEL
 *     builds the first level
 ****************************************************************/
void LevelOneHandler::handleLevel(int level, std::list<Bird*>& birds) {
   if (level == 1) {
      
      double size = 30.0;
      // spawns when there is nothing on the screen
      if (birds.size() == 0 && random(0, 15) == 1)
         birds.push_back(new Standard(size, 7.0));
      
      // spawn every 4 seconds
      if (random(0, 4 * 30) == 1)
         birds.push_back(new Standard(size, 7.0));
      
   } else if (next != nullptr) {
         
      next->handleLevel(level, birds);
      
   }
}


/******************************************************************
 * LEVEL TWO HANDLER :: HANDLE LEVEL
 *     builds the second level
 ****************************************************************/
void LevelTwoHandler::handleLevel(int level, std::list<Bird*>& birds) {
   if (level == 2) {
      
      double size = 25.0;
      // spawns when there is nothing on the screen
      if (birds.size() == 0 && random(0, 15) == 1)
         birds.push_back(new Standard(size, 7.0, 12));

      // spawn every 4 seconds
      if (random(0, 4 * 30) == 1)
         birds.push_back(new Standard(size, 5.0, 12));
      // spawn every 3 seconds
      if (random(0, 3 * 30) == 1)
         birds.push_back(new Sinker(size));
      
   } else if (next != nullptr) {
         
      next->handleLevel(level, birds);
      
   }
}


/******************************************************************
 * LEVEL THREE HANDLER :: HANDLE LEVEL
 *     builds the third level
 ****************************************************************/
void LevelThreeHandler::handleLevel(int level, std::list<Bird*>& birds) {
   if (level == 3) {
      
      double size = 20.0;
      // spawns when there is nothing on the screen
      if (birds.size() == 0 && random(0, 15) == 1)
         birds.push_back(new Standard(size, 5.0, 15));

      // spawn every 4 seconds
      if (random(0, 4 * 30) == 1)
         birds.push_back(new Standard(size, 5.0, 15));
      // spawn every 4 seconds
      if (random(0, 4 * 30) == 1)
         birds.push_back(new Sinker(size, 4.0, 22));
      // spawn every 4 seconds
      if (random(0, 4 * 30) == 1)
         birds.push_back(new Floater(size));
      
   } else if (next != nullptr) {
         
      next->handleLevel(level, birds);
      
   }
}


/******************************************************************
 * LEVEL FOUR HANDLER :: HANDLE LEVEL
 *     builds the fourth level
 ****************************************************************/
void LevelFourHandler::handleLevel(int level, std::list<Bird*>& birds) {
   if (level == 4) {
      
      double size = 15.0;
      // spawns when there is nothing on the screen
      if (birds.size() == 0 && random(0, 15) == 1)
         birds.push_back(new Standard(size, 4.0, 18));

      // spawn every 4 seconds
      if (random(0, 4 * 30) == 1)
         birds.push_back(new Standard(size, 4.0, 18));
      // spawn every 4 seconds
      if (random(0, 4 * 30) == 1)
         birds.push_back(new Sinker(size, 3.5, 25));
      // spawn every 4 seconds
      if (random(0, 4 * 30) == 1)
         birds.push_back(new Floater(size, 4.0, 25));
      // spawn every 4 seconds
      if (random(0, 4 * 30) == 1)
         birds.push_back(new Crazy(size));
      
   } else if (next != nullptr) {
         
      next->handleLevel(level, birds);
      
   }
}
