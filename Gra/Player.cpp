#include "Player.h"

void Player::initTexture()
{
	// za³adowanie tekstury z pliku
	if (!this->texture.loadFromFile("tekstury/trdragon.png"))
	{
		std::cout << "Blad:: Tekstura smoka nie moze byc zaladowana!" << "\n";
	}
}

void Player::initSprite()
{
	// ustawienie tekstury w sprajcie
	this->sprite.setTexture(this->texture);
	
	//zmiana rozmiaru sprajta zeby pasowal do okna
	this->sprite.scale(0.1f, 0.1f);


}

Player::Player()
{
	this->szybkoscporuszania = 2.f;

	this->initTexture();
	this->initSprite();

}

Player::~Player()
{

}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->szybkoscporuszania * dirX, this->szybkoscporuszania * dirY);
}

//funkcje
void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
