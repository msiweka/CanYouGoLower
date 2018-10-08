#include "Player.h"

#include <iostream>

Player::Player(sf::RenderWindow * parentWindow) :
	Object(parentWindow),
	jumpSpeed(0.7f),
	maxSpeed(0.5f),
	acceleration(0.0001f)
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
	if (velocity.x >= -maxSpeed && isOnGround())
		velocity.x -= acceleration;
}

void Player::moveRight()
{
	if (velocity.x <= maxSpeed && isOnGround())
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
		velocity.y = -jumpSpeed;
}

void Player::draw()
{
	if (sprite->getPosition().x + velocity.x >= 0 &&
		sprite->getPosition().x + width + velocity.x <= _parentWindow->getSize().x) // checking the borders
	{
		sprite->move(velocity);
	}
	else if (sprite->getPosition().x + velocity.x < 0)
	{
		sprite->setPosition(0, sprite->getPosition().y);
		
		if (getBottomPosition() < 600)
		{
			sprite->move(0, velocity.y);
			velocity.x = 0;
		}
	}
	else if (sprite->getPosition().x + width + velocity.x > _parentWindow->getSize().x)
	{
		sprite->setPosition(_parentWindow->getSize().x - width, sprite->getPosition().y);

		if (getBottomPosition() < 600)
		{
			sprite->move(0, velocity.y);
			velocity.x = 0;
		}
	}

	checkGravity();
	_parentWindow->draw(*sprite);
}

DIRECTION Player::getDirection()
{
	if (velocity.x < 0)
		return LEFT;

	if (velocity.x > 0)
		return RIGHT;

	return RIGHT;
}

bool Player::isOnGround()
{
	if (getBottomPosition() == 600)
		return true;

	return false;
}
