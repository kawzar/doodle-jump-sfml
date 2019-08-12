#include "pch.h"
#include "Game.h"


Game::Game()
{
	height = 800;
	width = 600;
	currentYPos = height;
	InitWindow();

	for (int i = 0; i < 5; i++) {
		SpawnPlatforms();
	}
}


Game::~Game()
{
}

void Game::InitWindow() {

	window = new RenderWindow(VideoMode(width, height), "Doodle Jump");
	window->setMouseCursorVisible(true);
	window->setFramerateLimit(60);
	//txBackground.loadFromFile("Images/mundo_fondo.jpg");
	//background.setTexture(txBackground);
}

void Game::Update() {
	for (std::list<Platform*>::iterator it = platforms.begin(); it != platforms.end(); it++) {
		(*it)->update();
	}
}

void Game::Draw() {
	window->clear();
	for (std::list<Platform*>::iterator it = platforms.begin(); it != platforms.end(); it++) {
		(*it)->draw(window);
	}
	window->display();
}

void Game::Loop() {
	while (window->isOpen()) {
		Update();
		Draw();
	}
}

void Game::SpawnPlatforms() {
	for (int i = 0; i < width / 100 - 2; i++) {
		int xPos = std::rand() % (width + 1);
		platforms.push_back(new Platform(Vector2f(xPos, currentYPos)));
	}

	currentYPos -= 75.0f;
}