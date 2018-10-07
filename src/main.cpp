#include <SFML/Graphics.hpp>

#include "Player.h"

int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "Can you go Lower??");
	Player player(&mainWindow);

	bool upPressed = false;
	bool downPressed = false;
	bool rightPressed = false;
	bool leftPressed = false;

	while (mainWindow.isOpen()) // main loop
	{
		mainWindow.clear(sf::Color::Black);
		sf::Event event;
		while (mainWindow.pollEvent(event)) // event loop
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				upPressed = true;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				rightPressed = true;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				leftPressed = true;

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
				rightPressed = false;

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
				leftPressed = false;

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
				upPressed = false;

		} // end event loop

		// Check Key pressing

		if (!leftPressed || !rightPressed)
			player.brake();

		if (upPressed)
			player.jump();

		if (leftPressed)
			player.moveLeft();

		if (rightPressed)
			player.moveRight();

		// Drawing objects

		player.draw();
		mainWindow.display();

	} // end main loop
	return 0;
}