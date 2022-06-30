#include "Block.h"

Block::Block() : m_Rectangle(Rectangle(0,0,0,0)), m_Direction(UP) {}

Block::Block(int x, int y, int w, int h, Direction d) : m_Rectangle({x, y, w, h}), m_Direction(d) {}