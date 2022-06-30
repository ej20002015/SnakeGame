#include "Food.h"

#include <random>
#include <time.h>

#include "Game.h"

Food::Food() : m_IsEaten(false)
{
  srand(time(NULL));
  int x = (rand() % (Game::SCREEN_WIDTH - 20)) + 10;
  int y = (rand() % (Game::SCREEN_HEIGHT - 20)) + 10;

  m_Rectangle.setRecCoordinates(x, y);
  m_Rectangle.setRecHeight(m_FoodSize);
  m_Rectangle.setRecWidth(m_FoodSize);
}

void Food::Reset()
{
  int x = (rand() % (Game::SCREEN_WIDTH - 20)) + 10;
  int y = (rand() % (Game::SCREEN_HEIGHT - 20)) + 10;

  m_IsEaten = false;
  m_Rectangle.setRecCoordinates(x, y);
}