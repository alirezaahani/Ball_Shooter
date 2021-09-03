#include "LEntity.h"
#include "LShooter.h"

LEntity::LEntity(LTexture* textrueSheet, int clip_x, int clip_y, int clip_w, int clip_h, int x, int y, int w, int h, SDL_Point velocity) {
	mTexture = textrueSheet;
	mTextureClip = {clip_x, clip_y, clip_w, clip_h};
	mX = x;
	mY = y;
	mW = w;
	mH = h;
	mVelocity = velocity;
	mVelocityCounter = 0;
}

LEntity::LEntity() {
	mTexture = nullptr;
	mTextureClip = {0, 0, 0, 0};
	mX = 0;
	mY = 0;
	mW = 0;
	mH = 0;
	mVelocity = {0, 0};
	mVelocityCounter = 0;
}

void LEntity::render(double angle, SDL_Point* center, SDL_RendererFlip flip) {
	mTexture->render(mX, mY, &mTextureClip, mW, mH, angle, center, flip);
}

bool LEntity::isOutSideWindow(int wH, int wW) {
	return (mX > wW ||
			mY > wH ||
			mX < (0 - mW )||
			mY < (0 - mH));
}

void LEntity::applyVelocity(SDL_Point friction, int counterValue) {
	if(mVelocityCounter % counterValue == 0) {
		mVelocity.x -= friction.x;
		mVelocity.y -= friction.y;
	}

	mX += mVelocity.x;
	mY += mVelocity.y;
	mVelocityCounter++;
}
