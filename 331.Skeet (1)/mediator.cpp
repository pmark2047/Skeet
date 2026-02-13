//
//  mediator.cpp
//  Lab03
//
//  Created by Elijah Dodge on 2/12/26.
//

#include "mediator.hpp"

void Mediator::notify(enum message msg)
{
   for (AbstractColleague* colleague : colleagues)
      colleague->notify(msg);
}
