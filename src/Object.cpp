#include "Object.h"

Object::Object(sf::RenderWindow * parentWindow) :
	velocity(0),
	gravity(0.5f),
	_parentWindow(parentWindow)
{
	mask = new sf::Color(249, 17, 255);
	textureImg = new sf::Image();
	texture = new sf::Texture();
	sprite = new sf::Sprite();
	
	width = 0;
	height = 0;
}

Object::~Object()
{
	delete mask;
	delete textureImg;
	delete texture;
	delete sprite;
}
