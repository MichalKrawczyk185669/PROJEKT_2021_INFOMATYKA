#include "Przeciwnicy.h"

void Przeciwnicy::initShape()
{
	this->shape.setRadius(rand() % 2 + 20);
	this->shape.setPointCount(rand() % 3 + 20);
	this->shape.setFillColor(sf::Color::White);
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
	return this->shape.getGlobalBounds();
}

Przeciwnicy::Przeciwnicy(float pos_x, float pos_y)
{
	
	this->initShape();
	this->initVariables();

	this->shape.setPosition(pos_x, pos_y);

}

Przeciwnicy::~Przeciwnicy()
{

}



//Funkcje

void Przeciwnicy::update()
{
	this->shape.move(0.f, 2.f);
}

void Przeciwnicy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}


