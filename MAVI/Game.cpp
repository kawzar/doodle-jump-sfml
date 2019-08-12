#include "pch.h"
#include "Game.h"


Game::Game()
{
	height = 800;
	width = 600;
	currentYPos = height;
	player = new Player(Vector2f(300, 100));
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
	view = View(Vector2f(width / 2, height / 2), Vector2f(width, height));
	cameraYPosition = height / 2;
	//txBackground.loadFromFile("Images/mundo_fondo.jpg");
	//background.setTexture(txBackground);
}

void Game::Update() {
	player->update();

	for (std::list<Platform*>::iterator it = platforms.begin(); it != platforms.end(); it++) {
		(*it)->update();

		if ((*it)->intersects(player->getColliderPosition())) {
			player->jump();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player->move(-10.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player->move(10.0f);
	}
	else
	{
		player->move(0.0f);
	}

	if (player->getColliderPosition().y > cameraYPosition) {
		cameraYPosition = view.getCenter().y + 100;
		view.setCenter(view.getCenter().x, cameraYPosition);
		window->setView(view);
	}
	
}

void Game::Draw() {
	window->clear();
	player->draw(window);

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
