#pragma once
#include <map>
#include "Player.h"
#include "KulaOgnia.h"
#include "Przeciwnicy.h"
#include "Background.h"
#include "UI.h"
class Game
{
	private:
		sf::RenderWindow* window;

		std::map<std::string, sf::Texture*> textures;
		std::vector<KulaOgnia*> kulaognia;
		std::vector<KulaOgnia*> to_delete;

		UI* ui;

		//Tlo	
		Background* background;

		//Gracz
		Player* player;


		//Przeciwnicy
		float spawnTimer;
		float spawntimerMax;
		std::vector<Przeciwnicy*> enemies;


		//funkcje prywatne
		void initWindow();
		void initTextures();
		void initUI();
		void initBackground();

		void initPlayer();
		void initEnemies();

    public:
		Game();
		virtual ~Game();

		//Funkcje
		void run();
		void updatePollEvents();
		void updateInput();
		void updateKulaOgnia();
		void updateEnemies();
		void update();
		void render();
};

