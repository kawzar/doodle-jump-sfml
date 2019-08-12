#include "pch.h"
#include "Player.h"


Player::Player(Vector2f position)
{
	_tx.loadFromFile("Images/jumper.png");
	_sprite.setTexture(_tx);
	_sprite.setOrigin(_tx.getSize().x / 2, _tx.getSize().y);

	x = position.x;
	y = position.y;
}


Player::~Player()
{
}

void Player::draw(RenderWindow * window) {
	window->draw(_sprite);
}

void Player::update() {
	updateMovement();

	if (velocityX > 0.0f && faceLeft)
	{
		_sprite.setScale(-1.f, 1.f);
		faceLeft = false;
	}
	else if (velocityX < 0.0f && !faceLeft)
	{
		_sprite.setScale(1.f, 1.f);
		faceLeft = true;
	}

	_sprite.setPosition(x, y);
}

bool Player::intersects(FloatRect rect) {
	return _sprite.getGlobalBounds().intersects(rect);
}

bool Player::intersects(Vector2f point) {
	return _sprite.getGlobalBounds().contains(point);
}

void Player::updateMovement() {

	velocityY += gravity;
	velocityX += accelerationX;
	velocityY += accelerationY;

	x += velocityX;
	y += velocityY;

	isGrounded = y >= 800;

	/*if (y > floor) {
		y = floor;
		colliding = false;
	}

	if (y < maxJump) {
		y = maxJump;
	}*/
}

void Player::move(float velocity) {
	velocityX = velocity;
}

void Player::jump() {
		velocityY = -15.0f;
}

FloatRect Player::getBounds() {
	return _sprite.getGlobalBounds();
}

Vector2f Player::getColliderPosition() {
	return Vector2f(_sprite.getPosition());
}