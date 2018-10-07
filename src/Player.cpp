#include "Player.h"

Player::Player(sf::RenderWindow * parentWindow) :
	Object(parentWindow),
	jumpSpeed(0.7f)
{
	textureImg->loadFromFile("..\\sprites\\player.png");
	texture->loadFromImage(*textureImg);
	sprite->setTexture(*texture);

	setSize();
}

Player::~Player()
{
}

void Player::jump()
{
	if (getBottomPosition() == 600)
		velocity.y = -jumpSpeed;
}
