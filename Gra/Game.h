#pragma once
#include "Player.h"

class Game
{
	private:
		sf::RenderWindow* window;

		//Gracz
		Player* player;


		//funkcje prywatne
		void initWindow();
		void initPlayer();

    public:
		Game();
		virtual ~Game();

		//Funkcje
		void run();
		void updatePollEvents();
		void updateInput();
		void update();
		void render();
};

