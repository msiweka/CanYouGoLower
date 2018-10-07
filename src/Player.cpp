#include "Player.h"

Player::Player(sf::RenderWindow * parentWindow) :
	Object(parentWindow)
{
	textureImg->loadFromFile("..\\sprites\\player.png");
	texture->loadFromImage(*textureImg);
	sprite->setTexture(*texture);

	setSize();
}

Player::~Player()
{
}

void Player::draw()
{
	_parentWindow->draw(*sprite);
}
