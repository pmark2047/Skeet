//
//  levelHandler.h
//  Lab03
//
//  Created by Peyton Markus on 2/14/26.
//

#pragma once
#include <list>
#include "bird.h"
#include <cassert>

// Base Handler
class LevelHandler {
   
protected:
   LevelHandler *next;
   
public:
   LevelHandler() : next(nullptr) {}
   virtual ~LevelHandler() {
      if (next != nullptr) {
         delete next;
      }
   }
   
   void setNext(LevelHandler* nextHandler) { next = nextHandler; }
   
   virtual void handleLevel(int level, std::list<Bird*>& birds) = 0;
   
};

// Level One Handler

class LevelOneHandler : public LevelHandler {
   
public:
   void handleLevel(int level, std::list<Bird*>& birds) override;
   
};

// Level Two Handler

class LevelTwoHandler : public LevelHandler {
   
public:
   void handleLevel(int level, std::list<Bird*>& birds) override;
   
};

// Level Three Handler

class LevelThreeHandler : public LevelHandler {
   
public:
   void handleLevel(int level, std::list<Bird*>& birds) override;
   
};

// Level Four Handler

class LevelFourHandler : public LevelHandler {
   
public:
   void handleLevel(int level, std::list<Bird*>& birds) override;
   
};
