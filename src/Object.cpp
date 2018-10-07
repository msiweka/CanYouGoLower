#include "Object.h"

Object::Object(sf::RenderWindow * parentWindow) :
	gravity(0.001f),
	width(0),
	height(0),
	jumped(false),
	_parentWindow(parentWindow)
{
	mask = new sf::Color(249, 17, 255);
	textureImg = new sf::Image();
	texture = new sf::Texture();
	sprite = new sf::Sprite();

	velocity.x = 0;
	velocity.y = 0;
}

Object::~Object()
{
	delete mask;
	delete textureImg;
	delete texture;
	delete sprite;
}

void Object::draw()
{
	sprite->move(velocity);
	checkGravity();
	_parentWindow->draw(*sprite);
}

void Object::setSize()
{
	height = sprite->getGlobalBounds().height;
	width = sprite->getGlobalBounds().width;
}

float Object::getBottomPosition()
{
	return sprite->getPosition().y + height;
}

void Object::moveLeft()
{
}

void Object::moveRight()
{
}

void Object::checkGravity()
{
	int groundHeight = 600;

	if (getBottomPosition() < groundHeight)
	{
		velocity.y += gravity;
	}
	else
	{
		sprite->setPosition(sprite->getPosition().x, 600 - height);
		velocity.y = 0;
		if (jumped)
		{
			velocity.x = 0;
			jumped = false;
		}
	}
}
