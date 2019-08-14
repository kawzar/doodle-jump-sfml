#include "pch.h"
#include "PlatformPool.h"
#include <iostream>

using namespace std;


PlatformPool::PlatformPool()
{
}


PlatformPool::~PlatformPool()
{
}

void PlatformPool::AddPlatform(Vector2f position) {
	bool added = false;
	for (std::list<Platform*>::iterator it = platforms.begin(); it != platforms.end(); it++) {
		if (!(*it)->isActive()) {
			(*it)->setPosition(position);
			(*it)->setActive(true);
			added = true;
			break;
		}
	}

	if (!added) {
		Platform* p = new Platform(position);
		platforms.push_back(p);
		p->setActive(true);
	}
}

void PlatformPool::Update(float maxY, float minY, FloatRect view, Player* player) {
	for (std::list<Platform*>::iterator it = platforms.begin(); it != platforms.end(); it++) {
		if ((*it)->isActive() && (*it)->getPosition().y > maxY +100){
			(*it)->setActive(false);
		}

		if ((*it)->isActive() && (*it)->intersects(player->getColliderPosition()))
		{
			player->jump();
		}

		(*it)->update();
	}
}

void PlatformPool::Draw(RenderWindow* wnd) {
	for (std::list<Platform*>::iterator it = platforms.begin(); it != platforms.end(); it++) {
		(*it)->draw(wnd);
	}
}