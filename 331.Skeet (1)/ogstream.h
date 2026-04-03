#pragma once

#include "position.h"
#include <string>

class ogstream
{
public:
   ogstream() {}

   // set position 
   void setPosition(const Position & pt);

   // drawing methods (Facade interface)
   void drawText(const Position & topLeft, const std::string & text) const;
   void drawLine(const Position & begin, const Position & end) const;
   void drawDot(const Position & pt) const;
   void drawDisk(const Position & center, double radius,
              double red, double green, double blue) const;

   // flush 
   void flush() const;

private:
   Position pt;
};
