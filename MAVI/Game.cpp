#include "pch.h"
#include "Game.h"


Game::Game()
{
	height = 800;
	width = 600;
	currentYPos = height*2;
	player = new Player(Vector2f(300, 100));
	pool = new PlatformPool();
	InitWindow();

	for (int i = 0; i < 10; i++) {
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

	sf::Vector2f viewCenter(view.getCenter());
	sf::Vector2f viewSize(view.getSize());

	sf::FloatRect currentViewRect(viewCenter - viewSize / 2.f, viewSize);

	pool->Update(viewCenter.y + viewSize.y, viewCenter.y +viewSize.y, currentViewRect, player);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player->getColliderPosition().x > 10)
	{
		player->move(-10.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player->getColliderPosition().x < 590)
	{
		player->move(10.0f);
	}
	else
	{
		player->move(0.0f);
	}

	if (player->getColliderPosition().y < cameraYPosition - 100) {
		for (int i = 0; i < 10; i++) {
			SpawnPlatforms();
		}

		cameraYPosition = view.getCenter().y - 100;
		view.setCenter(view.getCenter().x, cameraYPosition);
		window->setView(view);
	}
	
}

void Game::Draw() {
	window->clear();
	pool->Draw(window);
	player->draw(window);
	window->display();
}

void Game::Loop() {
	while (window->isOpen()) {
		Update();
		Draw();
	}
}

void Game::SpawnPlatforms() {

	if (currentYPos <= cameraYPosition + height / 2) {
		for (int i = 0; i < 3; i++) {
			int xPos = std::rand() % (width + 1);
			pool->AddPlatform(Vector2f(xPos, currentYPos));
		}
	}

	currentYPos -= 75.0f;
}
