#include "visitor.h"
#include "bird.h"
#include "bullet.h"
#include "effect.h"

VisitMove::VisitMove(std::list<Effect*>& effects)
   : effects(effects) {
}

void VisitMove::visit(Bird* bird)
{
   bird->advance();
}

void VisitMove::visit(Bullet* bullet)
{
   bullet->move(effects);
}

void VisitMove::visit(Effect* effect)
{
   effect->fly();
}

void VisitDraw::visit(Bird* bird)
{
   bird->draw();
}

void VisitDraw::visit(Bullet* bullet)
{
   bullet->output();
}

void VisitDraw::visit(Effect* effect)
{
   effect->render();
}
