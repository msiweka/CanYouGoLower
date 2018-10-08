#pragma once
#include "Object.h"


enum DIRECTION
{
	LEFT,
	RIGHT
};

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

	DIRECTION getDirection();

private:

	bool isOnGround();

	float jumpSpeed;
	float maxSpeed;
	float acceleration;
};

