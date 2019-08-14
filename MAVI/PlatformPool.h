#pragma once
#include <list>
#include "Platform.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

using namespace std;

class PlatformPool
{
public:
	PlatformPool();
	~PlatformPool();

	void AddPlatform(Vector2f position);
	void Update(float maxY, float cameraCenter, FloatRect pos, Player* player);
	void Draw(RenderWindow* wnd);

private:
	list<Platform*> platforms;
};

