#include "CApp.h"

void CApp::OnLoop() {

	// Bullets go future the higher the level
	for(auto i: mBullets) {
		i->applyVelocity({-1, 0}, (mScore < 60 ? (mScore + 1) * 4 : mScore + 1));
	}

	// Enemies fly to the shooter cordinates
	for(auto i: mEnemies) {
		i->applyVelocity({(i->mX - mShooter->mX) / 100, (i->mY - mShooter->mY) / 100}, 1000);
	}

	// Collision check for bullets hitting enemies
	for(auto i: mBullets) {
		i->collisionLoop(&mEnemies, &mBullets, &mScore);
		if(mShooterAlive) {
			// Collision check for bullets hitting back
			i->shooterCollisionCheck(&mBullets, mShooter, &mShooterAlive, &mHealthValue);
		}
	}

	// Collision check for enemies hitting shooter
	if(mShooterAlive) {
		mShooter->collisionLoop(&mEnemies, &mShooterAlive, &mHealthValue);
	}

	// Show red heart if less than 4
	if(mHealthValue < 4) {
		for(int i = 0; i < mHealthValue; i++) {
			mHealth[i]->mTextureClip = {0, 0, 100, 100};
		}
	} 
	else {
		for(int i = 0; i < mHealthValue; i++) {
			mHealth[i]->mTextureClip = {100, 0, 100, 100};
		}
	}

	if(mShooterAlive) {
		// Spawn enemies
		if(mEnemies.size() < (7 - (uint32_t)mHealthValue) * 3) {
			mEnemies.push_back(new LEntity(mSpriteSheet,
							0,
							0,
							100, 100,
							std::rand() % (mMainWindowWidth / 3), std::rand() % mMainWindowHeight, 50, 50, {10, 0}));
		}
	}

	// Neutral regeneration 
	if(mFrameCounter % 600 == 0 && mShooterAlive) {
		if(mHealthValue < 6) {
			mHealthValue += 1;
		}
	}


	// Cleanup loop for outside objects
	for(uint32_t i = 0; i < mBullets.size(); i++) {
		if(mBullets[i]->isOutSideWindow(mMainWindowHeight, mMainWindowWidth)) {
			delete mBullets[i];
			mBullets.erase(mBullets.begin() + i);
		}
	}

	for(uint32_t i = 0; i < mEnemies.size(); i++) {
		if(mEnemies[i]->isOutSideWindow(mMainWindowHeight, mMainWindowWidth)) {
			delete mEnemies[i];
			mEnemies.erase(mEnemies.begin() + i);
		}
	}

	mFrameCounter++;
}
