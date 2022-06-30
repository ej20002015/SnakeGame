#include "Game.h"

#include <iostream>

Game::Game(const std::string& gameName) : m_Window(nullptr), m_Renderer(nullptr), m_IsRunning(true), m_gameName(gameName) {}

bool Game::init()
{
  bool successful = true;
  //Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		successful = false;
	}
	else
	{
		//Create window
		m_Window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(m_Window == NULL)
		{
      std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
      successful = false;
    }
		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
		if (m_Renderer == NULL)
		{
			std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			successful = false;
		}
	}

  m_IsRunning = successful;
	return successful;
}

void Game::handleEvents()
{
  SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_QUIT:
				m_IsRunning = false;
				break;
      
      case SDL_KEYDOWN:
        handleKeyDownEvents(event);

      default:
        break;
		}
	}
}

bool Game::checkRectanglesCollide(const Coordinate* coordinatesA, const Coordinate* coordinatesB)
{
  if (coordinatesA[0].x < coordinatesB[1].x && coordinatesA[1].x > coordinatesB[0].x && coordinatesA[0].y < coordinatesB[1].y && coordinatesA[1].y > coordinatesB[0].y)
    return true;
  return false;
}

Game::~Game()
{
  if (m_Renderer)
    SDL_DestroyRenderer(m_Renderer);
  if (m_Window)
	  SDL_DestroyWindow(m_Window);
  if (SDL_WasInit(SDL_INIT_VIDEO))
	  SDL_Quit();
}