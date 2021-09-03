#pragma once
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

#include "LTexture.h"
#include "LEntity.h"
#include "LShooter.h"
#include "LBullet.h"

class CApp {

private:
    bool mIsRunning;  // Run the program or not, if false program will stop

    SDL_Window* mMainWindow;
    SDL_Renderer* mMainWindowRenderer;
    SDL_Surface* mMainWindowSurface;

    TTF_Font* mMainFont;
    LTexture* mText;
    LTexture* mSpriteSheet;
    SDL_Rect mSpriteSheetClip;

    std::vector<LBullet*> mBullets;
    std::vector<LEntity*> mEnemies;
    std::vector<LEntity*> mHealth;
    int mHealthValue;
    uint32_t mScore;
    uint32_t mFrameCounter;

    LShooter* mShooter;
    bool mShooterAlive;

    const std::string mMainWindowTitle = "Ball shooter";
    bool mGameScreen;

    int mMouseX, mMouseY;

public:
    CApp();
    int OnExecute(); // Executes render, event and main loop every cycle, runs cleanup on quit

    bool OnInit();

    void OnEvent(SDL_Event* event);
    void OnLoop();
    void OnRender();
    void OnCleanup();
    void EnterGame();
    void ResetGame();

    const static int mMainWindowHeight = 500; // Size for window
    const static int mMainWindowWidth = 1000;
};
