#ifndef SNAKEGAME_H_
#define SNAKEGAME_H_

#include "Game.h"

#include "SDL.h"
#include <string>

#include "Snake.h"
#include "Food.h"

class SnakeGame : public Game
{
  public:
    SnakeGame();
    virtual ~SnakeGame();

    virtual void render();
    virtual void update();
  
  protected:
    virtual void handleKeyDownEvents(SDL_Event& event);

  private:
    Snake* m_Snake;
    Food m_Food;
    void checkFoodEaten();
    bool checkSnakeDead();
};

#endif