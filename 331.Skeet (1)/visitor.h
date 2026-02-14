#pragma once
#include <list>

class Bird;
class Bullet;
class Effect;

class Visitor
{
public: 
   virtual ~Visitor() {}
   virtual void visit(Bird* bird) = 0;
   virtual void visit(Bullet* bullet) = 0;
   virtual void visit(Effect* effect) = 0;
};

class VisitMove : public Visitor
{
public:
   VisitMove(std::list<Effect*>& effects);
   void visit(Bird* bird) override;
   void visit(Bullet* bullet) override;
   void visit(Effect* effect) override;
  
private:
   std::list<Effect*>& effects;
};

class VisitDraw : public Visitor
{
public:
   void visit(Bird* bird) override;
   void visit(Bullet* bullet) override;
   void visit(Effect* effect) override;
};

// The base class for all flying objects (birds, bullets, and effects)
class FlyingObject
{
public:
   virtual void accept(Visitor* visitor) = 0;
};