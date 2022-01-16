#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Text {

private:
	std::string fontFilePath;

	sf::Font font;
	sf::Text* text;

	std::string toWrite;
	int fontSize;
	sf::Color color;

	bool clicked = false;

	float pos_x = 100.0, pos_y = 100.0;

	bool isClicking(sf::RenderWindow* window);
	bool releasedClicking(sf::RenderWindow* window);

public:

	Text(std::string fontPath);
	~Text();

	void loadFont();

	void render(sf::RenderTarget* target);

	bool isHovering(sf::RenderWindow* window) const;


	bool handleClicks(sf::RenderWindow* window);

	void setParameters(std::string toWrite, int fontSize, sf::Color color, float pos_x, float pos_y);

	sf::Text* getText() const;

};

