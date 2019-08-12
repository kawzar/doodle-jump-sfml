#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:
	Player(Vector2f position);
	~Player();

	void draw(RenderWindow * window);
	void update();
	bool intersects(FloatRect rect);
	bool intersects(Vector2f point);
	void move(float velocity);
	void jump();
	FloatRect getBounds();
	Vector2f getColliderPosition();


private:
	Texture _tx;
	Sprite _sprite;

	float x = 0;
	float y = 0;

	float velocityX = 0;
	float velocityY = 0;
	float accelerationX = 0;
	float accelerationY = 0;
	float gravity = 1;
	bool isGrounded;
	bool faceLeft = true;

	void updateMovement();
};

