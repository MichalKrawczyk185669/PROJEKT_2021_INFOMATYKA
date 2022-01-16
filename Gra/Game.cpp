#include "Game.h"
//Funkcje prywatne
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600),"Smok wawelski i owce", sf::Style::Close);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initTextures()
{
	this->textures["KulaOgnia"] = new sf::Texture();
	this->textures["KulaOgnia"]->loadFromFile("tekstury/KulaOgnia.png");
	this->textures["FlippedKulaOgnia"] = new sf::Texture();
	this->textures["FlippedKulaOgnia"]->loadFromFile("tekstury/FlippedKulaOgnia.png");
	this->textures["Background"] = new sf::Texture();
	this->textures["Background"]->loadFromFile("tekstury/background.jpg");

	this->enemyTextures["enemy1"] = new sf::Texture();
	this->enemyTextures["enemy1"]->loadFromFile("tekstury/owce/1.png");
	this->enemyTextures["enemy2"] = new sf::Texture();
	this->enemyTextures["enemy2"]->loadFromFile("tekstury/owce/2.png");
	this->enemyTextures["enemy3"] = new sf::Texture();
	this->enemyTextures["enemy3"]->loadFromFile("tekstury/owce/3.png");
	this->enemyTextures["enemy4"] = new sf::Texture();
	this->enemyTextures["enemy4"]->loadFromFile("tekstury/owce/4.png");
}
void Game::initPlayer()
{
	this->player = new Player();
}
void Game::initEnemies()
{
	this->spawntimerMax = 30.f;
	this->spawnTimer = this->spawntimerMax;
}
void Game::initUI() 
{
	this->ui = new UI("lora.ttf");
}
void Game::initBackground()
{
	this->background = new Background(this->textures["Background"], 0, 0);
	this->background->setSize(this->window->getDefaultView().getSize());
}
//tworzenie, niszczenie
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initPlayer();
	this->initEnemies();
	this->initUI();
	this->initBackground();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	//usuwanie tekstur
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	//kule ognia usuwanie
	for (auto* i : this->kulaognia)
	{
		delete i;
	}
	//usuwanie przeciwników
	for (auto* i : this->enemies)
	{
		delete i;
	}
}
// Funkcje
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event event;

	while (this->window->pollEvent(event))
	{
		if (event.Event::type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::updateInput()
{
	if (!isPaused) {
		// poruszanie smoka
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && std::min(player->getBodyBounds().left, player->getHeadBounds().left) >= 0) { ///TODO nie dziala 
			this->player->move(-1.f, 0.f);
		}
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && std::max(player->getHeadBounds().left + player->getHeadBounds().width, player->getBodyBounds().left + player->getBodyBounds().width) <= window->getSize().x) {
			this->player->move(1.f, 0.f);
		}
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player->getBodyBounds().top >= ui->getBackgroundHeight()) {
			this->player->move(0.f, -1.f);
		}
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (player->getBodyBounds().top + player->getBodyBounds().height) <= window->getSize().y) {
			this->player->move(0.f, 1.f);
		}
			

		// kule ognia strzaly
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
		{
			sf::Vector2f* mouthPos = this->player->getMouthPos();
			if (this->player->isRightFacing()) { // shoot right
				this->kulaognia.push_back(new KulaOgnia(this->textures["KulaOgnia"], mouthPos->x, mouthPos->y, 1.f, 0.f, 5.f));
			}
			else { //shoot left
				this->kulaognia.push_back(new KulaOgnia(this->textures["FlippedKulaOgnia"], mouthPos->x, mouthPos->y, -1.f, 0.f, 5.f));
			}

		}

		// mouse position left or right
		if (sf::Mouse::getPosition(*window).x >= player->getMiddlePos()) {
			// mouse is on the right side of the player
			player->faceRight();
		}
		else {
			// mouse is on the left side of the player
			player->faceLeft();
		}
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		if (canChangePause) {
			isPaused = !isPaused;
			ui->togglePauseScreen();
			std::cout << isPaused;
			canChangePause = false;
		}
	}
	else {
		canChangePause = true;
	}
}

void Game::updateKulaOgnia()
{
	sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), window->getDefaultView().getSize());
	unsigned counter = 0;
	for (auto *bullet : this->kulaognia)
	{
		bullet->update();
		if (!bullet->getBounds().intersects(windowBounds) ) // check if bullets go off screen
		{
			this->kulaognia.erase(this -> kulaognia.begin() + counter);
			delete bullet;
			--counter;
			break;
		}

		int i = 0;
		for (auto* enemy : enemies) {
			if (bullet->getBounds().intersects(enemy->getBounds())) { // check if bullets and enemies intersect
				this->kulaognia.erase(this->kulaognia.begin() + counter);
				delete bullet;
				--counter;

				
				enemies.erase(this->enemies.begin() + i);
				delete enemy;
				--i;

				ui->setScore(ui->getScore() + 1);

				break;

			}
			++i;
		}
		++counter;
	}
}

void Game::updateEnemies()
{
	sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), window->getDefaultView().getSize());
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawntimerMax)
	{
		sf::Texture* enemyTexture = new sf::Texture(*enemyTextures["enemy1"]);
		int r = rand() % 4;
		if (r == 0) enemyTexture = enemyTextures["enemy1"];
		if (r == 1) enemyTexture = enemyTextures["enemy2"];
		if (r == 2) enemyTexture = enemyTextures["enemy3"];
		if (r == 3) enemyTexture = enemyTextures["enemy4"];
		if (enemyTexture) {
			this->enemies.push_back(new Przeciwnicy(enemyTexture, rand() % this->window->getSize().y + 20.f, 20.f));
			this->spawnTimer = 0.f;
		}
		
	}
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		auto* enemy = enemies[i];
		enemy->update();
		//usuwanie przeciwników po prawej stronie ekranu
		if (!enemy->getBounds().intersects(windowBounds))
		{
			this->enemies.erase(this->enemies.begin() + i);
			delete enemy;
			break;
		}

		if (enemy->getBounds().intersects(player->getHeadBounds())) {
			this->enemies.erase(this->enemies.begin() + i);
			delete enemy;
			if (ui->getLives() > 0) {
				this->ui->setLives(ui->getLives() - 1);
			}
			break;
		}
		if (enemy->getBounds().intersects(player->getBodyBounds())) {
			this->enemies.erase(this->enemies.begin() + i);
			delete enemy;
			break;
		}
	}
}

void Game::update()
{
	if (!isPaused) {
		

		this->updatePollEvents();

		

		this->player->update();

		this->updateKulaOgnia();

		this->updateEnemies();
	}

	this->ui->update();

	this->updateInput();
}

void Game::render()
{
	this->window->clear();

	this->background->render(this->window);

	// render Kule Ognia

	this->player->render(*this->window);
	for (auto* bullet : this->kulaognia)
	{
		bullet->render(this->window);
	}

	//Przeciwnicy render

	for (auto* przeciwnicy : this->enemies)
	{
		przeciwnicy->render(this->window);
	}

	

	this->ui->render(this->window, this->window);

	this->window->display();
}
