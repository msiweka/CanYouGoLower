#pragma once
#include <SFML/Graphics.hpp>

// Avstract class for every drawable object
class Object
{
public:

	// Function to draw object on the screen
	virtual void draw() = 0;

protected:

	Object(sf::RenderWindow * parentWindow);
	virtual ~Object();

	float velocity;
	float gravity;

	float width;
	float height;

	sf::Texture * texture;
	sf::Image * textureImg;
	sf::RenderWindow * _parentWindow;
	sf::Color * mask;
	sf::Sprite * sprite;
};

