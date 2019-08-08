#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.h"

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

	void Update();
	void Draw();
	void InitWindow();
};

