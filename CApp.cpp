#include "CApp.h"

// Main function
int main() {
    CApp theApp;
    return theApp.OnExecute();

}

// App code
CApp::CApp() {
    mIsRunning = true;
}

// Execution of App code
int CApp::OnExecute() {

    if(OnInit() == false) {
        std::cout << "ERR::SDL::INIT::FAIL" << std::endl;
        return -1;
    }

    EnterGame();

    SDL_Event Event;

    while(mIsRunning) {

        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

void CApp::EnterGame() {
    while(!mGameScreen) {
        SDL_SetRenderDrawColor(mMainWindowRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(mMainWindowRenderer);

        mText->loadFromFont("Press any key to start",
            {0x00, 0x05, 0xFF, 0x00},
            mMainFont);
        mText->render((mMainWindowWidth - mText->getWidth())  / 2, (mMainWindowHeight - mText->getHeight()) / 2, nullptr);

        mText->loadFromFont("Ball shooter? (Alpha 0.0.1)",
            {29, 145, 60, 0x00},
            mMainFont);
        mText->render((mMainWindowWidth - mText->getWidth())  / 2, mText->getHeight(), nullptr);

        SDL_RenderPresent(mMainWindowRenderer);

        SDL_Event Event;
        SDL_PollEvent(&Event);

        // Quitting
        if(Event.type == SDL_QUIT) {
            mIsRunning = false;
            break;
        }

        if(Event.type == SDL_KEYDOWN) {
            mGameScreen = true;
            break;
        }

        mFrameCounter++;
    }
    ResetGame();
}


void CApp::ResetGame() {
    mShooterAlive = true;
    mScore = 0;
    mFrameCounter = 0;
    mGameScreen = false;
    mHealthValue = 6;
    mShooter->mX =  mMainWindowWidth - 50;
    mShooter->mY = mMainWindowHeight / 2;
    mMainFont = TTF_OpenFont("res/VT323-Regular.ttf", 40);
}
