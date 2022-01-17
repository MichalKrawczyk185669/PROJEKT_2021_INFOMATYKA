#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Time delayMS = sf::milliseconds(1000);

	sf::Texture* spriteToAnimate;

	sf::Texture** animationTextures;
	int animationFrames;


	int currentAnimationFrame;

	sf::Clock* clock;

public:
	Animation(int delayMS, int animationFrames);

	void update();

	sf::Texture* getAnimatedTexture() const;
	
};

