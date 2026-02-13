//
//  mediator.hpp
//  Lab03
//
//  Created by Elijah Dodge on 2/12/26.
//

#pragma once
#include <vector>
class AbstractColleague;

enum class message { HIT, BIRD_SHOT, BIRD_DIED, SHOOT, SHOT_FIRED };

class Mediator
{
protected:
   std::vector<AbstractColleague*> colleagues;
   
public:
   void notify(enum message msg);
   void enroll(AbstractColleague* c) { colleagues.push_back(c); }
   void unenroll(AbstractColleague* c)
   {
      colleagues.erase(std::remove(colleagues.begin(),
                                   colleagues.end(), c),
                    colleagues.end() );
   }
};
