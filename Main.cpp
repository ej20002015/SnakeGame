#include <iostream>
#include <memory>
#include <string>

#include "SDL.h"

#include "SnakeGame.h"

int main()
{
  std::unique_ptr<Game> snakeGame(new SnakeGame);

  snakeGame->init();

  while (snakeGame->getIsRunning())
  {
    snakeGame->handleEvents();
    snakeGame->update();
    snakeGame->render();
  }

  return 0;
}