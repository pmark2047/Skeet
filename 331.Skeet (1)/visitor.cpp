#include "visitor.h"
#include "bird.h"

// Accept Methods (Concrete Element behavior)
void Standard::accept(BirdVisitor& v)
{
  v.visitStandard(*this);
}

void Floater::accept(BirdVisitor& v)
{
  v.visitFloater(*this);
}

void Crazy::accept(BirdVisitor& v)
{
  v.visitCrazy(*this);
}

void Sinker::accept(BirdVisitor& v)
{
  v.visitSinker(*this);
}

// Concrete Visitor behavior
void DrawVisitor::visitStandard(Standard& bird)
{
  bird.draw();
}

void DrawVisitor::visitFloater(Floater& bird)
{
  bird.draw();
}

void DrawVisitor::visitCrazy(Crazy& bird)
{
  bird.draw();
}

void DrawVisitor::visitSinker(Sinker& bird)
{
  bird.draw();
}
