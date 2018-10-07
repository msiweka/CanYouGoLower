#pragma once
#include "Object.h"

// Class representate Player. Parent class Object
class Player : public Object
{
public:

	Player(sf::RenderWindow * parentWindow);
	virtual ~Player();

	virtual void draw();
private:

	float jumpSpeed;
};

