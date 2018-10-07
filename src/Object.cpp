#include "Object.h"

void Object::draw()
{
	checkGravity();
	_parentWindow->draw(*sprite);
}

Object::Object(sf::RenderWindow * parentWindow) :
	velocity(0),
	gravity(0.002f),
	width(0),
	height(0),
	_parentWindow(parentWindow),
	gravityMove(0)
{
	mask = new sf::Color(249, 17, 255);
	textureImg = new sf::Image();
	texture = new sf::Texture();
	sprite = new sf::Sprite();
}

Object::~Object()
{
	delete mask;
	delete textureImg;
	delete texture;
	delete sprite;
}

void Object::setSize()
{
	height = sprite->getGlobalBounds().height;
	width = sprite->getGlobalBounds().width;
}

void Object::checkGravity()
{
	int groundHeight = 600;

	if ((sprite->getPosition().y + height) < groundHeight)
	{
		gravityMove += gravity;
		sprite->move(velocity, gravityMove);
	}
	else
	{
		sprite->setPosition(sprite->getPosition().x, 600 - height);
		gravityMove = 0;
	}
}
