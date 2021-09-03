#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <vector>
#include <string>

#include "LTexture.h"

class LEntity {
public:

	int mX, mY, mW, mH;
	LTexture* mTexture;
	SDL_Rect mTextureClip;
	SDL_Point mVelocity;
	int mVelocityCounter;

	LEntity(LTexture* textrueSheet, int clip_x, int clip_y, int clip_w, int clip_h, int x, int y, int w, int h, SDL_Point velocity = {0, 0});

	LEntity();


	void render(double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

	bool isOutSideWindow(int wH, int wW);
	void applyVelocity(SDL_Point friction = {0, 0}, int counterValue = 50);
};
