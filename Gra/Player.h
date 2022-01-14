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

	bool facingLeft;
	bool facingRight;

	float attackCooldown;
	float attackCooldownMax;
	// Funkcje prywatne
	void initVariables();
	void initTexture();
	void initSprite();
public:
	Player();
	virtual ~Player();

	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	//funkcje

	void faceLeft();
	void faceRight();

	sf::Vector2f* getMouthPos() const;

	void move(const float dirX, const float dirY);
	const bool canAttack();
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

	bool isRightFacing();
};

