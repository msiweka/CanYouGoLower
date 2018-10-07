#pragma once
#include "Object.h"

// Class representate Player. Parent class Object
class Player : public Object
{
public:

	Player(sf::RenderWindow * parentWindow);
	virtual ~Player();

	virtual void moveLeft();
	virtual void moveRight();
	void brake();
	void jump();

	void draw();

private:

	bool isOnGround();

	float jumpSpeed;
	float maxSpeed;
	float acceleration;
};

