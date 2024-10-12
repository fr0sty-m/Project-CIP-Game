#include "utils/color.hpp"
#include "utils/vectors.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

namespace cbq {

class Display {
private:
  static SDL_Renderer *m_renderer;

public:
  Display(SDL_Window *window);
  ~Display() = default;

  static void Clear(Color color);
  static void Present();

  static void DrawRect(vec2<float> pos, vec2<float> size, Color color);

  static void DrawText(vec2<float> pos, float scale, Color color,
                       TTF_Font *font, const char *textString);

  static void DrawLine(vec2<float> pos1, vec2<float> pos2, Color color);

  static void Draw(SDL_Texture *texture, vec2<float> pos);
};

} // namespace cbq
