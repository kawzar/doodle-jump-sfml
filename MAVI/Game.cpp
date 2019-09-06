#include "pch.h"
#include "Game.h"
#include <string>



Game::Game()
{
	height = 850;
	width = 532;
	InitWindow();
	InitGame();
}


Game::~Game()
{
}

void Game::InitGame() {
	height = 850;
	width = 532;
	currentYPos = height + 200;
	maxMeters = 0.f;

	
	pool = new PlatformPool();

	for (int i = 0; i < 100; i++) {
		SpawnPlatforms();
	}
	player = new Player(Vector2f(300, 200));
	isGameOver = false;
}

void Game::InitWindow() {

	window = new RenderWindow(VideoMode(width, height), "Doodle Jump");
	window->setMouseCursorVisible(true);
	window->setFramerateLimit(60);
	view = View(Vector2f(width / 2, height / 2), Vector2f(width, height));
	cameraYPosition = height / 2;

	txBackground.loadFromFile("Images/background.png");
	background.setTexture(txBackground);
	background.setOrigin(view.getCenter());

	if (!font.loadFromFile("Less.otf"))
	{
		cout << "Couldn't load font";
	}

	txtMax = Text(std::to_string((int)maxMeters), font, 20);
	txtMax.setPosition(20, 50);
	txtMax.setOutlineColor(Color::Green);
	txtMax.setFillColor(Color::Black);
}

void Game::Update() {
	player->update();

	sf::Vector2f viewCenter(view.getCenter());
	sf::Vector2f viewSize(view.getSize());

	sf::FloatRect currentViewRect(viewCenter - viewSize / 2.f, viewSize);

	pool->Update(viewCenter.y + viewSize.y / 2.f, viewCenter.y, currentViewRect, player);

	maxMeters = std::max(player->getColliderPosition().y * -1, maxMeters);
	txtMax.setString(std::to_string((int)maxMeters));
	txtMax.setPosition(15, viewCenter.y + viewSize.y / 2 - 50);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player->getColliderPosition().x > 10)
	{
		player->move(-10.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player->getColliderPosition().x < width - 10)
	{
		player->move(10.0f);
	}
	else
	{
		player->move(0.0f);
	}

	if (player->getColliderPosition().y < cameraYPosition) {

		for (int i = 0; i < 3; i++) {
			SpawnPlatforms();
		}

		cameraYPosition = view.getCenter().y - 100;
		view.setCenter(view.getCenter().x, cameraYPosition);
		window->setView(view);
		background.setPosition(view.getCenter());
	}

	if (player->getColliderPosition().y > view.getCenter().y + view.getSize().y) {
		isGameOver = true;
	}

}

void Game::Draw() {
	window->clear();
	window->draw(background);
	pool->Draw(window);
	player->draw(window);
	window->draw(txtMax);
	window->display();
}

void Game::Loop() {
	while (window->isOpen()) {
		if (!isGameOver) {
			Update();
			Draw();
		} 
		else {
			ShowGameOverScreen();
		}

		EventHandling();
	}
}

void Game::SpawnPlatforms() {
	currentYPos -= 50.f;
	int maxPlatforms = std::rand() % 3 + 1;
	for (int i = 0; i < maxPlatforms; i++) {
		int xPos = std::rand() % (width - 99) + 50;
		pool->AddPlatform(Vector2f(xPos, currentYPos));
	}
}

void Game::ShowGameOverScreen() {
	window->clear();
	window->draw(background);
	txtGameOver = Text("Game Over! \nYour maximum distance was ", font, 20);
	txtGameOver.setPosition(100, view.getCenter().y - view.getSize().y / 2 + 100);
	txtGameOver.setFillColor(Color::Red);
	txtGameOver.setOutlineColor(Color::Black);

	txtRestart = Text("Press R to restart", font, 20);
	txtRestart.setPosition(100, view.getCenter().y - view.getSize().y / 2 + 200);
	txtRestart.setFillColor(Color::Red);
	txtRestart.setOutlineColor(Color::Black);

	window->draw(txtGameOver);
	window->draw(txtRestart);
	txtMax.setPosition(100, view.getCenter().y - view.getSize().y / 2 + 150);
	txtMax.setFillColor(Color::Red);
	txtMax.setOutlineColor(Color::Black);
	window->draw(txtMax);
	window->display();
}

void Game::EventHandling()
{
	Event evt;
	while (window->pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
			window->close();
			break;
		case Event::KeyPressed:
			if (evt.key.code == Keyboard::R && isGameOver)
			{
				InitGame();
				window->close();
				InitWindow();
			}
		}
	}
}