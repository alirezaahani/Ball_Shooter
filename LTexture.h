#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>

class LTexture {
public:
    LTexture(uint8_t ColorKeyR, uint8_t ColorKeyG, uint8_t ColorKeyB, SDL_Renderer* renderer);
    ~LTexture();

    bool loadFromFile(std::string path);
    bool loadFromFont(std::string textureText, SDL_Color textColor, TTF_Font* font);

    void free();
    void render(int x, int y, SDL_Rect* clip, int w = 0, int h = 0, double angle = 0.0, SDL_Point* center = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void setColor(uint8_t R, uint8_t G, uint8_t B);

    void setBlendMode(SDL_BlendMode blending);
    void setAlpha(uint8_t alpha);

    int getWidth();
    int getHeight();

private:
    SDL_Texture* mTexture;
    SDL_Renderer* mRenderer;
    SDL_Surface* mWindowSurface;

    int mWidth, mHeight;
    uint8_t mColorKeyR, mColorKeyG, mColorKeyB;

};
