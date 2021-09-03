#pragma once

#include "LEntity.h"
#include "LBullet.h"
#include <vector>

class LShooter : public LEntity {

public:
	LShooter(LTexture* textrueSheet, int clip_x, int clip_y, int clip_w, int clip_h, int x, int y, int w, int h, SDL_Point velocity = {0, 0});

	void setEntityPool(std::vector<LBullet*>* entityPool);
	void handelEvents(SDL_Event* event);
	void collisionLoop(std::vector<LEntity*>* enemies, bool* isAlive, int* health);
	void destorySelf(bool* isAlive, int* health);

	std::vector<LBullet*>* mEntityPool;

};
