#include "Player.h"

enum KEY
{
	LEFT_ARROW,
	RIGHT_ARROW
};

int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "Can you go Lower??");
	Player player(&mainWindow);

	bool spacePressed = false;
	bool downPressed = false;
	bool rightPressed = false;
	bool leftPressed = false;

	KEY lastKey;

	while (mainWindow.isOpen()) // main loop
	{
		mainWindow.clear(sf::Color::Black);
		sf::Event event;
		while (mainWindow.pollEvent(event)) // event loop
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				spacePressed = true;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				rightPressed = true;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				leftPressed = true;

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
				rightPressed = false;

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
				leftPressed = false;

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
				spacePressed = false;

		} // end event loop

		// Check Key pressing

		if (!leftPressed && !rightPressed)
			player.brake();

		if (spacePressed)
			player.jump();

		if (leftPressed)
		{
			player.moveLeft();
			lastKey = LEFT_ARROW;
		}

		if (rightPressed)
		{
			player.moveRight();
			lastKey = RIGHT_ARROW;
		}

		if (leftPressed && rightPressed)
		{
			player.brake();

			if (lastKey == LEFT_ARROW)
				player.moveLeft();

			else
				player.moveRight();
		}

		// Drawing objects

		player.draw();
		mainWindow.display();

	} // end main loop
	return 0;
}