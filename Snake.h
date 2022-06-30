#ifndef SNAKE_H_
#define SNAKE_H_

#include <vector>
#include <queue>
#include "SDL.h"

#include "Block.h"
#include "Direction.h"

class Snake
{
  public:

    Snake();
    ~Snake();

    void update();
    void addBlock();
    void setDirection(Direction direction);
    const std::vector<Block>& getBody() const { return m_Body; }

  private:

    std::vector<Block> m_Body;
    const int m_BlockWidth = 20;
    const int m_BlockHeight = 20;
    const int m_JumpSize = 20;
    const int m_BlockSpacing = 5;

};

#endif