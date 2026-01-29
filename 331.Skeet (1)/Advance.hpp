//
//  Advance.hpp
//  Lab03
//
//  Created by Elijah Dodge on 1/28/26.
//

#pragma once
#include "position.h"
#include "bird.h"


class Advance
{
public:
   virtual void advance(Bird& bird) = 0;
};


class Inertia : public Advance
{
public:
   void advance(Bird& bird) override;
};

class Gravity : public Advance
{
public:
   void advance(Bird& bird) override;
};

class Buoyancy : public Advance
{
public:
   void advance(Bird& bird) override;
};

class Chaos : public Advance
{
public:
   void advance(Bird& bird) override;
};
