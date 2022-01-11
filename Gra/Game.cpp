#include "Game.h"
//Funkcje prywatne
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600),"Smok wawelski i owce", sf::Style::Close || sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initPlayer()
{
	this->player = new Player();
}
//tworzenie, niszczenie
Game::Game()
{

	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
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
		/*if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
			this->window->close();*/

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
}

void Game::update()
{
	//while (window->isOpen())
	//{
	//	sf::Event event;
	//	while (window->pollEvent(event))
	//	{
	//		// jezeli zdarzenie zamknij - zamykamy okno
	//		if (event.type == sf::Event::Closed)
	//			this->window->close();
	//	}
	//}
	this->updatePollEvents();
	this->updateInput();


		

}

void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);
	this->window->display();
}
