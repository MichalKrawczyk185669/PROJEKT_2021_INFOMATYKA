#include "KulaOgnia.h"

//void KulaOgnia::initTexture()
//{
//	if (!this->tekstura.loadFromFile("tekstur.KulaOgnia.png"))
//	{
//		std::cout << "Blad::Teksstura Kuli Ognia nie moze byc zaladowana!" << "\n";
//	}
//}
//
//void KulaOgnia::initSprite()
//{
//	this->initSprite.setTexture(this->tekstura);
//	this->shape.scale(0.1f, 0.1f);
//}

KulaOgnia::KulaOgnia()
{
	/*this->initTexture();
	this->initSprite();*/
}

KulaOgnia::KulaOgnia(sf::Texture * texture, float pos_x, float pos_y, float dirx, float diry, float szbkosc_pocisku)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dirx;
	this->direction.y = diry;
	this->szybkoscpocisku=szbkosc_pocisku;
}

KulaOgnia::~KulaOgnia()
{
	
}

const sf::FloatRect KulaOgnia::getBounds() const
{
	return this->shape.getGlobalBounds();
}


void KulaOgnia::update()
{
	//poruszanie ogniem
	this->shape.move(this->szybkoscpocisku * this->direction);
}

void KulaOgnia::render(sf::RenderTarget* target)
{
	try
	{
		target->draw(this->shape);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	
}
