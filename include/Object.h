#pragma once
#include <SFML/Graphics.hpp>

enum POSITION
{
	LEFT_POS,
	RIGHT_POS,
	BOTTOM_POS,
	TOP_POS
};

// Parent class for every drawable object
class Object
{
public:

	// Function to draw object on the screen
	virtual void draw();

	std::map<POSITION, float> getPosition();

protected:

	Object(sf::RenderWindow * parentWindow);
	virtual ~Object();

	// Function to set size of your object
	// You must call it in every of yor child object after setting sprite
	void setSize();

	virtual void moveLeft();
	virtual void moveRight();

	void checkGravity();

	sf::Vector2f velocity;
	float gravity;

	float width;
	float height;

	sf::Texture * texture;
	sf::Image * textureImg;
	sf::RenderWindow * _parentWindow;
	sf::Color * mask;
	sf::Sprite * sprite;
};

