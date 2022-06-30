#include "SnakeGame.h"

SnakeGame::SnakeGame() : Game("Snake")
{
  m_Snake = new Snake();
  m_Food.Reset();
}

void SnakeGame::render()
{
  SDL_RenderClear(m_Renderer);if (checkRectanglesCollide(m_Snake->getBody().at(0).getCoordinates(), m_Food.getCoordinates()))
    m_Food.setIsEaten(true);
  SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
  SDL_RenderClear(m_Renderer);

  SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);

  const auto& snakeBody = m_Snake->getBody();
  for (const auto block : snakeBody)
  {
    SDL_RenderFillRect(m_Renderer, block.getSDLRectangle());
  }

  SDL_SetRenderDrawColor(m_Renderer, 0, 255, 0, 255);
  SDL_RenderFillRect(m_Renderer, m_Food.getSDLRectangle());

	SDL_RenderPresent(m_Renderer);
}

void SnakeGame::update()
{
  SDL_Delay(100);
  m_Snake->update();
  if (checkSnakeDead())
  {
    m_IsRunning = false;
    return;
  }
  checkFoodEaten();
  if (m_Food.getIsEaten())
  {
    m_Food.Reset();
    m_Snake->addBlock();
  }
}

void SnakeGame::handleKeyDownEvents(SDL_Event& event)
{
  switch (event.key.keysym.sym)
  {
  case SDLK_UP:
    m_Snake->setDirection(Direction::UP);
    break;

  case SDLK_RIGHT:
    m_Snake->setDirection(Direction::RIGHT);
    break;

  case SDLK_DOWN:
    m_Snake->setDirection(Direction::DOWN);
    break;

  case SDLK_LEFT:
    m_Snake->setDirection(Direction::LEFT);
    break;

  default:
    break;
  }
}

void SnakeGame::checkFoodEaten()
{
  const Coordinate* coordinatesA = m_Snake->getBody().front().getCoordinates();
  const Coordinate* coordinatesB = m_Snake->getBody().front().getCoordinates();
  if (checkRectanglesCollide(m_Snake->getBody().at(0).getCoordinates(), m_Food.getCoordinates()))
    m_Food.setIsEaten(true);
}

bool SnakeGame::checkSnakeDead()
{
  const Coordinate* headCoordinates = m_Snake->getBody().front().getCoordinates();
  for (int i = 1; i < m_Snake->getBody().size(); ++i)
  {
    const Coordinate* blockCoordinate = m_Snake->getBody().at(i).getCoordinates();
    if (checkRectanglesCollide(headCoordinates, blockCoordinate))
      return true;
  }
  return false;
}

SnakeGame::~SnakeGame()
{
  delete m_Snake;
}