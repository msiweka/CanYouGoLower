#include "Object.h"

Object::Object(sf::RenderWindow * parentWindow) :
	gravity(0.001f),
	width(0),
	height(0),
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
	checkGravity();
	sprite->move(velocity);
	_parentWindow->draw(*sprite);
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
		velocity.y += gravity;
	}
	else
	{
		sprite->setPosition(sprite->getPosition().x, 600 - height);
		velocity.y = 0;
	}
}
