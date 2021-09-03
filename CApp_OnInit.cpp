#include "CApp.h"

bool CApp::OnInit() {

    // Init SDL video mode
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "ERR::SDL::INIT::SDL " << SDL_GetError() << std::endl;
        return false;
    }

    // Create main window
    mMainWindow = SDL_CreateWindow(mMainWindowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mMainWindowWidth, mMainWindowHeight, SDL_WINDOW_SHOWN);
    if(mMainWindow == nullptr) {
        std::cout << "ERR::SDL::INIT::WINDOW " << SDL_GetError() << std::endl;
        return false;
    }

    // Create main window's renderer - try hardware acceleration
    mMainWindowRenderer = SDL_CreateRenderer(mMainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(mMainWindowRenderer == nullptr) {
        std::cout << "WARN::SDL::INIT::RENDERER::RENDERER_HARDWARE " << SDL_GetError() << std::endl;
        mMainWindowRenderer = nullptr;

        // Create main window's renderer - try software acceleration
        mMainWindowRenderer = SDL_CreateRenderer(mMainWindow, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC);
        if(mMainWindowRenderer == nullptr) {
            std::cout << "ERR::SDL::INIT::RENDERER::RENDERER_SOFTWARE " << SDL_GetError() << std::endl;
            return false;
        }

    }

    if(strcmp(SDL_GetCurrentVideoDriver(), "wayland") == 0) {
        std::cout << "WARN::WAYLAND" << std::endl;
        SDL_SetWindowBordered(mMainWindow, SDL_TRUE);
        mMainWindowSurface = SDL_GetWindowSurface(mMainWindow);
    }

    // Enable png loading
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        std::cout << "ERR::SDL::INIT::IMG " << IMG_GetError() << std::endl;
        return false;
    }

    // Enable true type font
    if(TTF_Init() == -1) {
        std::cout << "ERR::SDL::INIT::TTF " << TTF_GetError() << std::endl;
        return false;
    }


    /* Load media */

    // Load font
    mMainFont = TTF_OpenFont("res/VT323-Regular.ttf", 40);
    if(mMainFont == nullptr) {
        std::cout << "ERR::SDL::LOAD::FONT " << TTF_GetError() << std::endl;
        return false;
    }

    mText = new LTexture(0xFF, 0xFF, 0xFF, mMainWindowRenderer);
    mText->setBlendMode(SDL_BLENDMODE_BLEND);

    mSpriteSheet = new LTexture(0x00, 0xFF, 0xFF, mMainWindowRenderer);
    mSpriteSheet->loadFromFile("res/sprites.png");

    mShooter = new LShooter(mSpriteSheet, 100, 0, 100, 100, mMainWindowWidth - 50, mMainWindowHeight / 2, 50, 50);
    mShooter->setEntityPool(&mBullets);

    mHealthValue = 6;
    for(int i = 0; i < mHealthValue; i++) {
        mHealth.push_back(new LEntity(mSpriteSheet, 100, 0, 100, 100, i * 50, 0, 50, 50));
    }

    mShooterAlive = true;
    mScore = 0;
    mFrameCounter = 0;
    mGameScreen = false;

    std::cout << "INFO::INIT::SUCCESS" << std::endl;
    return true;
}
