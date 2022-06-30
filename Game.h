#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>
#include <string>

#include "Rectangle.h"

class Game
{
  public:

    static const int SCREEN_WIDTH = 400;
    static const int SCREEN_HEIGHT = 400;

    Game(const std::string& gameName);
    virtual ~Game();

    bool init();
    virtual void render() = 0;
    virtual void update() = 0;
    void handleEvents();

    bool getIsRunning() const { return m_IsRunning; }

  protected:

    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;

    bool m_IsRunning;

    virtual void handleKeyDownEvents(SDL_Event& event) = 0;
    bool checkRectanglesCollide(const Coordinate* coordinatesA, const Coordinate* coordinatesB);
  
  private:
    std::string m_gameName;

};

#endif