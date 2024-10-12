#include "window/display.hpp"

#include <iostream>

namespace cbq {

enum ENGINE_STATE { SPLASH, RUN };

class Framework {
private:
  Framework() = default;
  ~Framework() = default;

  static Framework *s_instance;

  int m_width, m_height;
  const char *m_title;
  uint32_t m_style;

  ENGINE_STATE engineState;

  // Clock clock;
  // Clock splashClock
  float m_deltaTime;

  SDL_Window *m_window;
  Display *m_display;

  bool init();
  bool initVars();
  bool initWindow();

  void gameLoop();
  void handleEvents();

  void updateDeltaTime();
  void update();
  void updateSplash();

  void render();

public:
  void SetApp(/* Application *app */);
  void Start(int WIDTH, int HEIGHT, const char *TITLE, uint32_t STYLE);

  static Framework *Get() {
    return (s_instance != nullptr) ? s_instance : new Framework();
  }
};

} // namespace cbq
