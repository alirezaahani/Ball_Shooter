#pragma once

#include "LEntity.h"

class LBullet : public LEntity {

public:
	LBullet(LTexture* textrueSheet, int clip_x, int clip_y, int clip_w, int clip_h, int x, int y, int w, int h, SDL_Point velocity = {0, 0});

	void handelEvents(SDL_Event* event);
	void collisionLoop(std::vector<LEntity*>* enemies, std::vector<LBullet*>* bullet_pool, uint32_t* mScore);
	void destorySelf(std::vector<LBullet*>* bullets);
	void shooterCollisionCheck(std::vector<LBullet*>* bullet_pool, LEntity* shooter, bool* shooter_alive, int* health);
};
