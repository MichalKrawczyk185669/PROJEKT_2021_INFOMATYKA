#pragma once
#include <map>
#include <fstream>

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

		std::map<std::string, sf::Texture*> enemyTextures;

		int lastSaveIndex = 0;
		const std::string savePath = "saves/";

		UI* ui;

		//Tlo	
		Background* background;

		//Gracz
		Player* player;

		bool facingByKeyboard = false;

		bool isPaused = false;
		bool isPauseShown = false;
		bool isHelpShown = false;

		bool canChangePause = true;
		bool canChangeHelp = true;

		bool startGameCall = false;
		bool exitGameCall = false;

		
		int* lastLoadFiles;
		bool firstLoadFilesUpdate = true;

		//Przeciwnicy
		float spawnTimer;
		float spawntimerMax = 25.f;
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

		void saveGame();
		void loadGame(int saveIndex);
		void findLastSaveIndex();

		void updateLastSaveFiles();
};

