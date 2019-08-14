#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Platform
{
public:
	Platform(Vector2f position);
	~Platform();

	void draw(RenderWindow * window);
	void update();
	bool intersects(FloatRect rect);
	bool intersects(Vector2f point);
	Vector2f getPosition();
	bool isActive();
	void setActive(bool active);
	void setPosition(Vector2f pos);

private:
	Texture _tx;
	Sprite _sprite;

	float x = 0;
	float y = 0;
	bool active;
};

