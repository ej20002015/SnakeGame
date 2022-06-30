#ifndef FOOD_H_
#define FOOD_H_

#include "SDL.h"

#include "Coordinate.h"
#include "Rectangle.h"

class Food
{
  public:
    Food();

    void Reset();

    bool getIsEaten() { return m_IsEaten; }
    void setIsEaten(bool isEaten) { m_IsEaten = isEaten; }

    const SDL_Rect* getSDLRectangle() const { return m_Rectangle.getSDLRectangle(); }
    void setCoordinates(int x, int y) { m_Rectangle.setRecCoordinates(x, y); }

    const Coordinate* getCoordinates() const { return m_Rectangle.getCoordinates(); }
  
  private:
    bool m_IsEaten;
    const int m_FoodSize = 10;
    Rectangle m_Rectangle;
};

#endif