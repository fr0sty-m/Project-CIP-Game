#include "loop.hpp"
#include "log/log.hpp"
#include <SDL.h>
#include <iostream>

namespace cbq {

Framework *Framework::s_instance = nullptr;

bool Framework::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    fr0sty::error("SDL could not initialize!: ", SDL_GetError());
    return -1;
  }

  if (this->initVars() < 0) {
    fr0sty::error("Could not initialize variables!: ", SDL_GetError());
  }

  if (this->initWindow() < 0) {
    fr0sty::error("Could not initialize window!: ", SDL_GetError());
  }

  return 0;
}

bool Framework::initVars() {
  //

  return 0;
}

bool Framework::initWindow() {
  m_window =
      SDL_CreateWindow("Engine Window", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

  m_display = new Display(m_window);

  return 0;
}

void Framework::Start(int WIDTH, int HEIGHT, const char *TITLE,
                      uint32_t STYLE) {
  if (init() != 0) {
    fr0sty::error("Could not initialize everything!");
  }
}

} // namespace cbq
