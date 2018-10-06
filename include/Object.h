#pragma once
#include <SFML/Graphics.hpp>


class Object
{
public:

	Object(sf::RenderWindow * parentWindow);
	virtual ~Object();

private:
	float velocity;
	int gravity;
	sf::Texture texture;
	sf::Image textureImg;
	sf::RenderWindow * _parentWindow;
};

