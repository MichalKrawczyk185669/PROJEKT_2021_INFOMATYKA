#pragma once
#include <map>
#include "Player.h"
#include "KulaOgnia.h"
class Game
{
	private:
		sf::RenderWindow* window;

		std::map<std::string, sf::Texture*> textures;
		std::vector<KulaOgnia*> kulaognia;


		//Gracz
		Player* player;


		//funkcje prywatne
		void initWindow();
		void initTextures();
		void initPlayer();

    public:
		Game();
		virtual ~Game();

		//Funkcje
		void run();
		void updatePollEvents();
		void updateInput();
		void updateKulaOgnia();
		void update();
		void render();
};

