#ifndef BLOCK_H_
#define BLOCK_H_

#include "SDL.h"

#include "Direction.h"
#include "Rectangle.h"
#include "Coordinate.h"

class Block
{
  public:

    Block();
    Block(int x, int y, int w, int h, Direction d);
    
    const Direction getDirection() const { return m_Direction; }
    void setDirection(Direction direction) { m_Direction = direction; } 

    const SDL_Rect* getSDLRectangle() const { return m_Rectangle.getSDLRectangle(); }
    void setCoordinates(int x, int y) { m_Rectangle.setRecCoordinates(x, y); }

    const Coordinate* getCoordinates() const { return m_Rectangle.getCoordinates(); }
  
  private:

    Rectangle m_Rectangle;
    Direction m_Direction;
};

#endif