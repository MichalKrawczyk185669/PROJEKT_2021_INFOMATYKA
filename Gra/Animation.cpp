#include "Animation.h"
#include <iostream>

Animation::Animation(int delayMS, int animationFrames)
{

	this->animationFrames = animationFrames;

	animationTextures = new sf::Texture * [animationFrames];

	for (int i = 0; i < animationFrames; i++) {
		animationTextures[0] = new sf::Texture();
		animationTextures[0]->loadFromFile("tekstury/animated/" + std::to_string(i + 1) + ".png");
	}



	clock = new sf::Clock();

	clock->restart();
	
}

void Animation::update()
{
	//std::cout << delayMS.asMilliseconds() << '\n';
	if (abs(clock->getElapsedTime().asMilliseconds() - delayMS.asMilliseconds()) <= 10){
		
		// cycle through frames
		currentAnimationFrame += 1;
		if (currentAnimationFrame == animationFrames) {
			currentAnimationFrame = 0;
		}

		std::cout << currentAnimationFrame;

		clock->restart();
	}
}

sf::Texture* Animation::getAnimatedTexture() const
{
	return animationTextures[currentAnimationFrame];
}
