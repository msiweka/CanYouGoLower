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

	float velocity;
	const float gravity;

	float width;
	float height;

	sf::Texture * texture;
	sf::Image * textureImg;
	sf::RenderWindow * _parentWindow;
	sf::Color * mask;
	sf::Sprite * sprite;

private:

	void checkGravity();

	float gravityMove;
};

