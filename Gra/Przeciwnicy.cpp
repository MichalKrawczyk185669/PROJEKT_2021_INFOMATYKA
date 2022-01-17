#include "Przeciwnicy.h"

void Przeciwnicy::initShape()
{	
	sprite = new sf::Sprite();

	sprite->scale(0.06f, 0.06f);

	//std::cout << sprite->getGlobalBounds().width << ' ' << sprite->getGlobalBounds().height << '\n';
}

void Przeciwnicy::initVariables()
{
	this->type  =0;
	this->hp    =0;
	this->hpMax =10;
	this->damage=1;
	this->points=5;
}

const sf::FloatRect Przeciwnicy::getBounds() const
{
	return this->sprite->getGlobalBounds();
}

Przeciwnicy::Przeciwnicy(sf::Texture* texturefloat, float pos_x, float pos_y)
{
	
	this->initShape();
	this->initVariables();

	this->sprite->setTexture(*texturefloat);

	this->sprite->setPosition(pos_x, pos_y);

}

Przeciwnicy::~Przeciwnicy()
{

}



//Funkcje

void Przeciwnicy::update()
{
	this->sprite->move(0.0f, 2.0f);
}

void Przeciwnicy::render(sf::RenderTarget* target)
{
	target->draw(*sprite);
}


