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

	float attackCooldown;
	float attackCooldownMax;
	// Funkcje prywatne
	void initVariables();
	void initTexture();
	void initSprite();
public:
	Player();
	virtual ~Player();

	const::sf::Vector2f& getPos() const;

	//funkcje

	void move(const float dirX, const float dirY);
	const bool canAttack();
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

};

