#pragma once
#include "Object.h"

// Class representate Player. Parent class Object
class Player : public Object
{
public:

	Player(sf::RenderWindow * parentWindow);
	virtual ~Player();

	void jump();

private:

	float jumpSpeed;
};

