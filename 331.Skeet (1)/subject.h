/*************************************************************************
 * Header file:
 *       subject
 * Author: 
 *       Diego Estrada
 *************************************************************************/

#pragma once
#include <list>
#include "observer.h"

/*************************************************************************
 * Subject
 * The subject of the observer pattern
 *************************************************************************/
class Subject
{
public:
   void subscribe(Observer* observer)
   {
      observers.push_back(observer);
   }

   void unsubscribe(Observer* observer)
   {
      observers.remove(observer);
   }

protected:
   void notify(EventType event, int value)
   {
      for (auto observer : observers)
         observer->update(event, value);
   }

private:
   std::list<Observer*> observers;
};
