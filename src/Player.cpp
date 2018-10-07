#include "Player.h"

Player::Player(sf::RenderWindow * parentWindow) :
	Object(parentWindow),
	jumpStrenght(20),
	jumpSpeed(0)
{
	textureImg->loadFromFile("..\\sprites\\player.png");
	texture->loadFromImage(*textureImg);
	sprite->setTexture(*texture);

	setSize();
}

Player::~Player()
{
}
