#include "ogstream.h"

using namespace std;

#ifdef __APPLE__
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#else
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif

/************************
 * SET POSITION
 ************************/
void ogstream::setPosition(const Position & pt)
{
   this->pt = pt;
}

/************************
 * DRAW TEXT
 ************************/
void ogstream::drawText(const Position & topLeft, const string & text) const
{
   void* pFont = GLUT_TEXT;

   glColor3f(1.0, 1.0, 1.0);
   glRasterPos2f(topLeft.getX(), topLeft.getY());

   for (const char* p = text.c_str(); *p; p++)
      glutBitmapCharacter(pFont, *p);
}

/************************
 * DRAW LINE
 ************************/
void ogstream::drawLine(const Position & begin, const Position & end) const
{
   glBegin(GL_LINES);

   glVertex2f(begin.getX(), begin.getY());
   glVertex2f(end.getX(), end.getY());

   glEnd();
}

/************************
 * DRAW DOT
 ************************/
void ogstream::drawDot(const Position & pt) const
{
   glBegin(GL_POINTS);

   glVertex2f(pt.getX(), pt.getY());

   glEnd();
}

/************************
 * FLUSH 
 ************************/
void ogstream::flush() const
{
   glFlush();
}
