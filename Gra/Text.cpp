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

void Text::setParameters(std::string toWrite, int fontSize, sf::Color color, float pos_x, float pos_y)
{
	text->setCharacterSize(fontSize);
	text->setFillColor(color);
	text->setPosition(pos_x, pos_y);
	text->setString(toWrite);
}

