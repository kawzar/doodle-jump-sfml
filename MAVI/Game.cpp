#include "pch.h"
#include "Game.h"


Game::Game()
{
	platform = new Platform(Vector2f(50, 50));

	InitWindow();
}


Game::~Game()
{
}

void Game::InitWindow() {
	window = new RenderWindow(VideoMode(800, 600), "Doodle Jump");
	window->setMouseCursorVisible(true);
	window->setFramerateLimit(60);
	//txBackground.loadFromFile("Images/mundo_fondo.jpg");
	//background.setTexture(txBackground);
}

void Game::Update() {
	platform->update();
}

void Game::Draw() {
	window->clear();
	platform->draw(window);
	window->display();
}

void Game::Loop() {
	while (window->isOpen()) {
		Update();
		Draw();
	}
}