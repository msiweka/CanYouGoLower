#include <SFML/Graphics.hpp>

#include "Player.h"

int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "Can you go Lower??");
	Player player(&mainWindow);

	while (mainWindow.isOpen()) // main loop
	{
		mainWindow.clear(sf::Color::Black);
		sf::Event event;
		while (mainWindow.pollEvent(event)) // event loop
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();

		} // end event loop

		player.draw();
		mainWindow.display();
	} // end main loop
	return 0;
}