#include "Text.h"
#include <iostream>


Text::Text(std::string fontPath) {
	this->fontFilePath = fontPath;
	this->loadFont();

	text = new sf::Text("Hello", this->font, 50);
}

Text::~Text() {

}

void Text::loadFont() {
	try {
		this->font.loadFromFile(this->fontFilePath);
	}
	catch (const std::exception&) {

	}
}


void Text::render(sf::RenderTarget* target) {
	target->draw(*this->text);
}

bool Text::isHovering(sf::RenderWindow* window) const
{
	
	if (this->text->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y)) { // mouse inside button
		return true;
	}
	return false;
}

bool Text::isClicking(sf::RenderWindow* window)
{
	if (isHovering(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		clicked = true;
		return true;
	}
	return false;
}

bool Text::releasedClicking(sf::RenderWindow* window)
{
	if (!isClicking(window) && clicked) {
		clicked = false;
		return true;
	}
	return false;
}




bool Text::handleClicks(sf::RenderWindow* window)
{
	isClicking(window);
	if (releasedClicking(window)) {
		return true; // user clicked
	}
	return false;

}

void Text::setParameters(std::string toWrite, int fontSize, sf::Color color, float pos_x, float pos_y)
{
	text->setCharacterSize(fontSize);
	text->setFillColor(color);
	text->setPosition(pos_x, pos_y);
	text->setString(toWrite);
}

sf::Text* Text::getText() const
{
	return text;
}

