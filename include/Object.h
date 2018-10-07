#pragma once
#include <SFML/Graphics.hpp>

// Parent class for every drawable object
class Object
{
public:

	// Function to draw object on the screen
	virtual void draw();

protected:

	Object(sf::RenderWindow * parentWindow);
	virtual ~Object();

	// Function to set size of your object
	// You must call it in every of yor child object after setting sprite
	void setSize();
	float getBottomPosition();

	virtual void moveLeft();
	virtual void moveRight();

	void checkGravity();

	sf::Vector2f velocity;
	float gravity;

	float width;
	float height;

	bool jumped;

	sf::Texture * texture;
	sf::Image * textureImg;
	sf::RenderWindow * _parentWindow;
	sf::Color * mask;
	sf::Sprite * sprite;
};

