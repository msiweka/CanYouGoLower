#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode(1920, 1080), "Can you go Lower??");

	while (mainWindow.isOpen()) // main loop
	{
		sf::Event event;
		while (mainWindow.pollEvent(event)) // event loop
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();

		} // end event loop

		mainWindow.clear();
		mainWindow.display();
	} // end main loop
	return 0;
}