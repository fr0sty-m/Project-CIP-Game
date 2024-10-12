#include "display.hpp"
#include "utils/color.hpp"
#include "utils/vectors.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

namespace cbq {

SDL_Renderer *Display::m_renderer = nullptr; // Assuming a single renderer

Display::Display(SDL_Window *window) {}

void Display::Clear(Color color) {
  SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, 255);
  SDL_RenderClear(m_renderer);
}

void Display::Present() { SDL_RenderPresent(m_renderer); }

void Display::DrawRect(vec2<float> pos, vec2<float> size, Color color) {
  SDL_Rect rect;
  rect.x = static_cast<int>(pos.x);
  rect.y = static_cast<int>(pos.y);
  rect.w = static_cast<int>(size.x);
  rect.h = static_cast<int>(size.y);

  SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, 255);
  SDL_RenderFillRect(m_renderer, &rect);
}

void Display::DrawText(vec2<float> pos, float scale, Color color,
                       TTF_Font *font, const char *textString) {
  SDL_Surface *surface =
      TTF_RenderText_Solid(font, textString, {color.r, color.g, color.b, 255});
  SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);

  SDL_Rect dstRect;
  dstRect.x = static_cast<int>(pos.x);
  dstRect.y = static_cast<int>(pos.y);
  dstRect.w = static_cast<int>(surface->w * scale);
  dstRect.h = static_cast<int>(surface->h * scale);

  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0); // Reset color (optional)
  SDL_RenderCopy(m_renderer, texture, nullptr, &dstRect);

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}

void Display::DrawLine(vec2<float> pos1, vec2<float> pos2, Color color) {
  SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, 255);
  SDL_RenderDrawLine(m_renderer, static_cast<int>(pos1.x),
                     static_cast<int>(pos1.y), static_cast<int>(pos2.x),
                     static_cast<int>(pos2.y));
}

void Display::Draw(SDL_Texture *texture, vec2<float> pos) {
  SDL_Rect dstRect;
  dstRect.x = static_cast<int>(pos.x);
  dstRect.y = static_cast<int>(pos.y);

  int width, height;
  SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
  dstRect.w = width;
  dstRect.h = height;

  SDL_RenderCopy(m_renderer, texture, nullptr, &dstRect);
}

} // namespace cbq
