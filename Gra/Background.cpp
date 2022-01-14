#include "Background.h"

Background::Background()
{
}

Background::Background(sf::Texture* texture, float pos_x, float pos_y)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
}

Background::~Background()
{
}

const sf::FloatRect Background::getBounds() const
{
	return sf::FloatRect();
}

void Background::update()
{
}

void Background::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Background::setSize(sf::Vector2f window_size)
{
	float s_x = window_size.x / this->shape.getLocalBounds().width;
	float s_y = window_size.y / this->shape.getLocalBounds().height;
	shape.setScale(s_x, s_y);
}

void Background::setSize(float width, float height)
{
	float s_x = width / this->shape.getLocalBounds().width;
	float s_y = height / this->shape.getLocalBounds().height;
	shape.setScale(s_x, s_y);
}
