#include "CApp.h"

void CApp::OnRender() {

    // Clear renderer screen
    SDL_SetRenderDrawColor(mMainWindowRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(mMainWindowRenderer);

	if(mShooterAlive) {
		// Health render
		mText->loadFromFont("Health",
			{0x00, 128, 0, 0x00},
			mMainFont);
		mText->render(10, 50, nullptr);

		// Score render
		mText->loadFromFont("Score: " + std::to_string(mScore),
			{220, 161, 35, 0x00},
			mMainFont);
		mText->render(10, 50 + mText->getHeight(), nullptr);

		// Enemy level render
		mText->loadFromFont("Enemy level: " + std::to_string((7 - mHealthValue) * 3),
			{158, 6, 6, 0x00},
			mMainFont);
		mText->render(10, 100 + mText->getHeight(), nullptr);
    }

    if(!mShooterAlive) {
		// Game over scene
		mText->loadFromFont(" GAME OVER ",
			{255, 0, 0, 0x00},
			mMainFont);
		mText->render((mMainWindowWidth - mText->getWidth())  / 2, (mMainWindowHeight - mText->getHeight()) / 2, nullptr);

		// After some delay goto EnterGame scene
		if(mFrameCounter % 200 == 0) {
			mGameScreen = false;
			EnterGame();
		}
    }

	// Render Entities
	for(auto i: mEnemies) {
		i->render();
	}

    // Render Entities
	for(auto i: mBullets) {
		i->render();
	}
	
	// Render health points
	for(int i = 0; i < mHealthValue; i++) {
		mHealth[i]->render();
	}

	// Render shooter
	if(mShooterAlive) {
		mShooter->render();
	}

    // Update screen
    SDL_RenderPresent(mMainWindowRenderer);
}
