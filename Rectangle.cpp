#include "Rectangle.h"

Rectangle::Rectangle()
{
  setRecCoordinates(0, 0);
  setRecHeight(0);
  setRecWidth(0);
}

Rectangle::Rectangle(int x, int y, int w, int h)
{
  setRecCoordinates(x, y);
  setRecHeight(h);
  setRecWidth(w);
}

void Rectangle::setRecCoordinates(int x, int y)
{
  m_Rectangle.x = x;
  m_Rectangle.y = y;
  m_Coordinates[0] = {x, y};
  m_Coordinates[1] = {x + m_Rectangle.w, y + m_Rectangle.h};
}