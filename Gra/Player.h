#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include "Animation.h"

class Player
{
private:
	sf::Sprite sprite;

	sf::Sprite spriteBody;
	sf::Sprite spriteHead;

	Animation* playerAnimation;
	const int animationFrames = 4;

	sf::Texture texture;
	sf::Texture bodyTexture;
	sf::Texture headTexture;

	sf::Texture animatedBodyTexture;
	sf::IntRect animatedBodyRect;

	sf::Clock clock;


	float szybkoscporuszania;

	bool facingLeft;
	bool facingRight;

	float attackCooldown;
	float attackCooldownMax;
	// Funkcje prywatne
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();
public:
	Player();
	virtual ~Player();

	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const sf::FloatRect getBodyBounds() const;
	const sf::FloatRect getHeadBounds() const;

	void setPosition(float posX, float posY);

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

	sf::Uint64 getMiddlePos();
};

