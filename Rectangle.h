#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "SDL.h"
#include "Coordinate.h"

class Rectangle
{
  public:
    Rectangle();
    Rectangle(int x, int y, int w, int h);

    const SDL_Rect* getSDLRectangle() const { return &m_Rectangle; }
    const Coordinate* getCoordinates() const { return m_Coordinates; };

    void setRecCoordinates(int x, int y);
    void setRecHeight(int h) { m_Rectangle.h = h; }
    void setRecWidth(int w) { m_Rectangle.w = w; }

  private:
    SDL_Rect m_Rectangle;
    Coordinate m_Coordinates[2];
};

#endif