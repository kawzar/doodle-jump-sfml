#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.h"
#include <list>
#include "Player.h"

using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	~Game();
	void Loop();

private:
	RenderWindow *window;
	Texture txBackground;
	Sprite background;

	int width, height;
	float currentYPos;
	list<Platform*> platforms;
	Player* player;

	void Update();
	void Draw();
	void InitWindow();
	void SpawnPlatforms();
};

