#include "ogstream.h"
#include <string>

using namespace std;

#ifdef __APPLE__
#include <openGL/gl.h>
#include <GLUT/glut.h>
#elif __linux__
#include <GL/gl.h>
#include <GL/glut.h>
#elif _WIN32
#include <GL/glut.h>
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
 * DRAW DISK
 ************************/
void ogstream::drawDisk(const Position& center, double radius,
                        double red, double green, double blue) const
{
   const double increment = M_PI / radius;

   glBegin(GL_TRIANGLES);
   glColor3f(red, green, blue);

   Position pt1;
   pt1.setX(center.getX() + (radius * cos(0.0)));
   pt1.setY(center.getY() + (radius * sin(0.0)));
   Position pt2(pt1);

   for (double radians = increment; radians <= M_PI * 2.0 + .5; radians += increment)
   {
      pt2.setX(center.getX() + (radius * cos(radians)));
      pt2.setY(center.getY() + (radius * sin(radians)));

      glVertex2f(center.getX(), center.getY());
      glVertex2f(pt1.getX(), pt1.getY());
      glVertex2f(pt2.getX(), pt2.getY());

      pt1 = pt2;
   }

   glEnd();
}

/************************
 * FLUSH 
 ************************/
void ogstream::flush() const
{
   glFlush();
}
