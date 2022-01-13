#include "Player.h"

void Player::initVariables()
{
	this->szybkoscporuszania = 2.f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
}

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
	/*this->szybkoscporuszania = 2.f;*/
	this->initVariables();
	this->initTexture();
	this->initSprite();

}

Player::~Player()
{

}

const::sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->szybkoscporuszania * dirX, this->szybkoscporuszania * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 2.f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if(this->attackCooldown< this->attackCooldownMax)
	  this->attackCooldown += 0.5f;

}

//funkcje
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
