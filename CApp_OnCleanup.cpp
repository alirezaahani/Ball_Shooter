#include "CApp.h"

void CApp::OnCleanup() {

    delete mText;

    for(uint32_t i = 0; i < mBullets.size(); i++) {
        delete mBullets[i];
    }
    mBullets.clear();

    for(uint32_t i = 0; i < mEnemies.size(); i++) {
        delete mEnemies[i];
    }
    mEnemies.clear();

    delete mShooter;

    TTF_CloseFont(mMainFont);
    mMainFont = nullptr;

    // Destroy Main window
    SDL_DestroyWindow(mMainWindow);
    mMainWindow = nullptr;

    // Destroy renderer
    SDL_DestroyRenderer(mMainWindowRenderer);
    mMainWindowRenderer = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

}
