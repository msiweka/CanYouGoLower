#include "Player.h"

Player::Player(sf::RenderWindow * parentWindow) :
	Object(parentWindow),
	jumpSpeed(0.7f),
	maxSpeed(0.5f),
	acceleration(0.1f)
{
	textureImg->loadFromFile("..\\sprites\\player.png");
	texture->loadFromImage(*textureImg);
	sprite->setTexture(*texture);

	setSize();
}

Player::~Player()
{
}

void Player::moveLeft()
{
	if (velocity.x != -maxSpeed && isOnGround())
		velocity.x -= acceleration;
}

void Player::moveRight()
{
	if (velocity.x != maxSpeed && isOnGround())
		velocity.x += acceleration;
}

void Player::brake()
{
	if (isOnGround())
		velocity.x = 0;
}

void Player::jump()
{
	if (isOnGround())
	{
		velocity.y = -jumpSpeed;
		jumped = true;
	}
}

bool Player::isOnGround()
{
	if (getBottomPosition() == 600)
		return true;

	return false;
}
