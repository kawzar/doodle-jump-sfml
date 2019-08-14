#include "pch.h"
#include "Platform.h"
#include <iostream>;

using namespace std;


Platform::Platform(Vector2f position)
{
	_tx.loadFromFile("Images/platform1.png");
	_sprite.setTexture(_tx);
	_sprite.setOrigin(_tx.getSize().x / 2, _tx.getSize().y);

	x = position.x;
	y = position.y;
	active = false;
}


Platform::~Platform()
{
}

void Platform::draw(RenderWindow * window) {
	if (active) {
		window->draw(_sprite);
	}
}

void Platform::update() {
	if (active) {
		_sprite.setPosition(x, y);
	}
}

bool Platform::intersects(FloatRect rect) {
	return _sprite.getGlobalBounds().intersects(rect);
}

bool Platform::intersects(Vector2f point) {
	return _sprite.getGlobalBounds().contains(point);
}

Vector2f Platform::getPosition() {
	return _sprite.getPosition();
}

bool Platform::isActive()
{
	return active;
}

void Platform::setActive(bool a)
{
	active = a;
}

void Platform::setPosition(Vector2f pos)
{
	x = pos.x;
	y = pos.y;
}
