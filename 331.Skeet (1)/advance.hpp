//
//  advance.hpp
//  Lab03
//
//  Created by Elijah Dodge on 1/30/26.
//

#pragma once
#include "position.h"

class Bird;

class Advance
{
public:
   void advance(Bird& bird);
   
protected:
   virtual void setDrag(Bird& bird); // step 1
   void setInertia(Bird& bird); // step 2
   virtual void setGravity(Bird& bird); // step 3
   virtual void setErratic(Bird& bird); // step 4
   void checkBounds(Bird& bird); // step 5
};



class StandardAdvance: public Advance
{
protected:
   void setDrag(Bird& bird) override;
};

class FloaterAdvance: public Advance
{
protected:
   void setDrag(Bird& bird) override;
   void setGravity(Bird& bird) override;
};

class SinkerAdvance: public Advance
{
protected:
   void setGravity(Bird& bird) override;
};

class CrazyAdvance: public Advance
{
protected:
   void setErratic(Bird& bird) override;
};
