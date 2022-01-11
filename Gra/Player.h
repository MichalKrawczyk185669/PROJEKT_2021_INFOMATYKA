#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float szybkoscporuszania;

	// Funkcje prywatne
	void initTexture();
	void initSprite();
public:
	Player();
	virtual ~Player();

	//funkcje

	void move(const float dirX, const float dirY);


	void update();
	void render(sf::RenderTarget& target);

};

