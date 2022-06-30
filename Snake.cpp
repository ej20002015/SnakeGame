#include "Snake.h"

#include "Game.h"

int mod(int x, int y)
{
  int r = x % y;
  return r < 0 ? r + y : r;
}

Snake::Snake()
{
  m_Body.push_back(Block((int)(Game::SCREEN_WIDTH * 0.5), (int)(Game::SCREEN_HEIGHT * 0.5), m_BlockWidth, m_BlockHeight, UP));
  setDirection(UP);
}

void Snake::update()
{
  for (int i = m_Body.size() - 1; i > 0; --i)
  {
    Block& block = m_Body.at(i);
    Block previousBlock = m_Body.at(i - 1);
    block = previousBlock;
  }

  Block& headBlock = m_Body.at(0);
  SDL_Rect rectangle = *(headBlock.getSDLRectangle());
  int x = rectangle.x;
  int y = rectangle.y;
  if (headBlock.getDirection() == Direction::UP)
    headBlock.setCoordinates(x, mod((y - m_JumpSize - m_BlockSpacing), Game::SCREEN_HEIGHT));
  else if (headBlock.getDirection() == Direction::RIGHT)
    headBlock.setCoordinates(mod((x + m_JumpSize + m_BlockSpacing), Game::SCREEN_WIDTH), y);
  else if (headBlock.getDirection() == Direction::DOWN)
    headBlock.setCoordinates(x, mod((y + m_JumpSize + m_BlockSpacing), Game::SCREEN_HEIGHT));
  else
    headBlock.setCoordinates(mod((x - m_JumpSize - m_BlockSpacing), Game::SCREEN_WIDTH), y);
}

void Snake::addBlock()
{
  Block endBlock = m_Body.back();
  SDL_Rect rectangle = *(endBlock.getSDLRectangle());
  int x = rectangle.x;
  int y = rectangle.y;
  Block newBlock;
  switch (endBlock.getDirection())
  {
    case UP:
      newBlock.setDirection(UP);
      newBlock.setCoordinates(x, y + m_BlockHeight + m_BlockSpacing);
      break;

    case RIGHT:
      newBlock.setDirection(RIGHT);
      newBlock.setCoordinates(x - m_BlockWidth - m_BlockSpacing, y);
      break;

    case DOWN:
      newBlock.setDirection(DOWN);
      newBlock.setCoordinates(x, y - m_BlockHeight - m_BlockSpacing);
      break;

    case LEFT:
      newBlock.setDirection(LEFT);
      newBlock.setCoordinates(x + m_BlockWidth + m_BlockSpacing, y);
      break;
    
    default:
      break;
  }

  m_Body.push_back(newBlock);
}

void Snake::setDirection(Direction direction)
{
  Block& headBlock = m_Body.front();
  Direction headDirection = headBlock.getDirection();
  if (((headDirection == UP && direction == DOWN) || (headDirection == DOWN && direction == UP)))
  {
    return;
  }
  if (((headDirection == RIGHT && direction == LEFT) || (headDirection == LEFT && direction == RIGHT)))
    return;

  headBlock.setDirection(direction);
}


Snake::~Snake()
{
  m_Body.clear();
}