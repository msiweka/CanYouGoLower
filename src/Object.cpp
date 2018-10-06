#include "Object.h"

Object::Object(sf::RenderWindow * parentWindow) :
	velocity(0),
	gravity(1),
	_parentWindow(parentWindow)
{
}

Object::~Object()
{
}
