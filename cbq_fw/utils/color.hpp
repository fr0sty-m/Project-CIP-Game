#ifndef CBQ_FRAMEWORK_COLOR_HPP
#define CBQ_FRAMEWORK_COLOR_HPP

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_stdinc.h>
#include <cstdint>

typedef struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;

  SDL_Color toSDLColor() const { return {r, g, b, 255}; }

  Color blend(const Color &other, float factor) const {
    return Color(static_cast<Uint8>(r * (1 - factor) + other.r * factor),
                 static_cast<Uint8>(g * (1 - factor) + other.g * factor),
                 static_cast<Uint8>(b * (1 - factor) + other.b * factor));
  }
} Color;

// Custom colors
const Color RED(255, 0, 0);
const Color GREEN(0, 255, 0);
const Color BLUE(0, 0, 255);
const Color WHITE(255, 255, 255);
const Color BLACK(0, 0, 0);
const Color YELLOW(255, 255, 0);
const Color CYAN(0, 255, 255);
const Color MAGENTA(255, 0, 255);

#endif
