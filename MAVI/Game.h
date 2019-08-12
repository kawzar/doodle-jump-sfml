#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.h"
#include <list>

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

	Platform* platform;
	int width, height;
	float currentYPos;
	list<Platform*> platforms;

	void Update();
	void Draw();
	void InitWindow();
	void SpawnPlatforms();
};

