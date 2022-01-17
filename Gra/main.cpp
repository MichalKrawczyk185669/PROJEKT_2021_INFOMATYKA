#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Game.h"
#include <time.h>




int main()
{
	srand(static_cast<unsigned int>(time(0)));

	Game game;
	game.run();

	return 0;
}

