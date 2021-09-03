#include "LShooter.h"

void LShooter::setEntityPool(std::vector<LBullet*>* entityPool) {
	mEntityPool = entityPool;
}

void LShooter::handelEvents(SDL_Event* Event) {
	// Mouse handling
	if(Event->type == SDL_MOUSEMOTION || Event->type == SDL_MOUSEBUTTONDOWN) {
		switch(Event->type) {
			case SDL_MOUSEBUTTONDOWN:
				// Spawn bullet into bullet entity pool
				mEntityPool->push_back(new LBullet(mTexture,
									(std::rand() % 2) * 100,
									(std::rand() % 2) * 100,
									100, 100,
									mX, Event->motion.y + 13, 25, 25, {-10, 0}));
				break;
		}
	}
}

void LShooter::collisionLoop(std::vector<LEntity*>* enemies, bool* isAlive, int* health) {
	SDL_Rect ownCollisonBox = {mX, mY, mW, mH};

	for(uint32_t i = 0; i < enemies->size(); i++) {

		SDL_Rect otherCollisonBox = {enemies->at(i)->mX, enemies->at(i)->mY, enemies->at(i)->mW, enemies->at(i)->mH};

		if(SDL_HasIntersection(&ownCollisonBox, &otherCollisonBox)) {
			delete enemies->at(i);
			enemies->erase(enemies->begin() + i);
			destorySelf(isAlive, health);
		}
	}
}

void LShooter::destorySelf(bool* isAlive, int* health) {
	(*health)--;
	if(*health == 0) {
		*isAlive = false;
	}
}

LShooter::LShooter(LTexture* textrueSheet, int clip_x, int clip_y, int clip_w, int clip_h, int x, int y, int w, int h, SDL_Point velocity) {
	mTexture = textrueSheet;
	mTextureClip = {clip_x, clip_y, clip_w, clip_h};
	mX = x;
	mY = y;
	mW = w;
	mH = h;
	mVelocity = velocity;
	mVelocityCounter = 0;
}
