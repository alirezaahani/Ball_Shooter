#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {

    // Quitting
    if(Event->type == SDL_QUIT) {
        mIsRunning = false;
    }

    // Keyboard handling
    else if(Event->type == SDL_KEYDOWN) {
        switch(Event->key.keysym.sym) {
			case SDLK_UP:
				// Instant health regeneration with score
				if(mScore > 50 && mHealthValue < 6 && mShooterAlive) {
					mScore -= 10;
					mHealthValue++;
				}
        }
    }

	// Mouse handling
	if(Event->type == SDL_MOUSEMOTION || Event->type == SDL_MOUSEBUTTONDOWN) {

		switch(Event->type) {
			case SDL_MOUSEMOTION:
				mMouseX = Event->motion.x;
				mMouseY = Event->motion.y;
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
		}
	}

	if(mShooterAlive) {
		// Move shooter to mouse cords
		if((mMouseY > 0) && (mMouseY < (mMainWindowHeight - mShooter->mH))) {
			mShooter->mY = mMouseY;
			mShooter->mX = mMainWindowWidth - mShooter->mW;
		}
	}

	if(mShooterAlive) {
		mShooter->handelEvents(Event);
	}

}
