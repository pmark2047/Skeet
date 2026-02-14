#ifndef VISITOR_H
#define VISITOR_H

#include "bird.h"

// Abstract Visitor
class BirdVisitor
{
public: 
  virtual ~BirdVisitor() {}
  
  virtual void visitStandard(Standard& bird) = 0;
  virtual void visitFloater(Floater& bird) = 0;
  virtual void visitCrazy(Crazy& bird) = 0;
  virtual void visitSinker(Sinker& bird) = 0;
};

// Concrete Visitor
class DrawVisitor : public BirdVisitor
{
public:
    void visitStandard(Standard& bird) override;
    void visitFloater(Floater& bird) override;
    void visitCrazy(Crazy& bird) override;
    void visitSinker(Sinker& bird) override;
};

#endif
