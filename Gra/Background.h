#pragma once
#include <SFML/Graphics.hpp>
class Background {
private:
	sf::Sprite shape;

public:
	Background();
	Background(sf::Texture* texture, float pos_x, float pos_y);

	virtual ~Background();
	//kula
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);

	void setSize(sf::Vector2f);
	void setSize(float width, float height);
};


