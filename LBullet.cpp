#include "LBullet.h"

LBullet::LBullet(LTexture* textrueSheet, int clip_x, int clip_y, int clip_w, int clip_h, int x, int y, int w, int h, SDL_Point velocity) {
	mTexture = textrueSheet;
	mTextureClip = {clip_x, clip_y, clip_w, clip_h};
	mX = x;
	mY = y;
	mW = w;
	mH = h;
	mVelocity = velocity;
	mVelocityCounter = 0;
}

void LBullet::handelEvents(SDL_Event* Event) {

}

void LBullet::collisionLoop(std::vector<LEntity*>* enemies, std::vector<LBullet*>* bullet_pool, uint32_t* mScore) {
	SDL_Rect ownCollisonBox = {mX, mY, mW, mH};

	for(uint32_t i = 0; i < enemies->size(); i++) {

		SDL_Rect otherCollisonBox = {enemies->at(i)->mX, enemies->at(i)->mY, enemies->at(i)->mW, enemies->at(i)->mH};

		if(SDL_HasIntersection(&ownCollisonBox, &otherCollisonBox)) {
			delete enemies->at(i);
			enemies->erase(enemies->begin() + i);
			destorySelf(bullet_pool);
			(*mScore) += (rand() % 10) + 1;
		}
	}

}

void LBullet::shooterCollisionCheck(std::vector<LBullet*>* bullet_pool, LEntity* shooter, bool* shooter_alive, int* health) {
	if(SDL_sqrt(SDL_pow(mX - shooter->mX, 2) + SDL_pow(mY - shooter->mY, 2)) > 30) {
		SDL_Rect ownCollisonBox = {mX, mY, mW, mH};
		SDL_Rect otherCollisonBox = {shooter->mX, shooter->mY, shooter->mH, shooter->mW};

		if(SDL_HasIntersection(&ownCollisonBox, &otherCollisonBox)) {
			destorySelf(bullet_pool);
			(*health)--;
			if(*health == 0) {
				*shooter_alive = false;
			}
		}
	}

}

void LBullet::destorySelf(std::vector<LBullet*>* bullets) {
	for(uint32_t i = 0; i < bullets->size(); i++) {
		if(bullets->at(i) == this) {
			bullets->erase(bullets->begin() + i);
			delete this;
		}
	}
}
