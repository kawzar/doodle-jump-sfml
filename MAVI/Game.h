#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.h"
#include <list>
#include "Player.h"
#include "PlatformPool.h"

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
	View view;

	int width, height;
	float currentYPos, cameraYPosition;
	bool isGameOver = false;
	float maxMeters;
	list<Platform*> platforms;
	Player* player;
	PlatformPool* pool;
	Text txtMax;
	Text txtGameOver;
	Font font;

	void Update();
	void Draw();
	void InitWindow();
	void SpawnPlatforms();
};

