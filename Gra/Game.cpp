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
}
void Game::initPlayer()
{
	this->player = new Player();
}
//tworzenie, niszczenie
Game::Game()
{

	this->initWindow();
	this->initTextures();
	this->initPlayer();
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
	// poruszanie smoka
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		this->player->move(0.f, 1.f);

	// kule ognia strzaly
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		
		this->kulaognia.push_back(new KulaOgnia(this->textures["KulaOgnia"], this->player->getPos().x+90, this->player->getPos().y+36.5, 1.f, 0.f, 5.f));
	}

}

void Game::updateKulaOgnia()
{
	unsigned counter = 0;
	for (auto *bullet : this->kulaognia)
	{
		bullet->update();
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			delete bullet;
			this->kulaognia.erase(this -> kulaognia.begin() + counter);
			--counter;
			

		}
		++counter;
	}
}

void Game::update()
{
	this->updatePollEvents();

	

	this->updateInput();
	
	this->player->update();

	this->updateKulaOgnia();

}

void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);
	for (auto* bullet : this->kulaognia)
	{
		bullet->render(this->window);
	}
	this->window->display();
}
