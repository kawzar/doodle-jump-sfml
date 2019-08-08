#include "pch.h"
#include "Platform.h"
#include <iostream>;

using namespace std;


Platform::Platform(Vector2f position)
{
	_tx.loadFromFile("Images/platform1.png");
	_sprite.setTexture(_tx);
	_sprite.setScale(0.1, 0.1);
	_sprite.setOrigin(_tx.getSize().x / 2, _tx.getSize().y);

	x = position.x;
	y = position.y;
}


Platform::~Platform()
{
}

void Platform::draw(RenderWindow * window) {
	window->draw(_sprite);
}

void Platform::update() {
	_sprite.setPosition(x, y);
}

bool Platform::intersects(FloatRect rect) {
	return _sprite.getGlobalBounds().intersects(rect);
}

bool Platform::intersects(Vector2f point) {
	return _sprite.getGlobalBounds().contains(point);
}