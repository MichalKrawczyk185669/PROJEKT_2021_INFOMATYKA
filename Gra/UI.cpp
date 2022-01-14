#include "UI.h"
#include <iostream>

UI::UI(std::string fontFilePath)
{
	this->smallLeftText = new Text(fontFilePath);
	this->leftText = new Text(fontFilePath);
	this->smallRightText = new Text(fontFilePath);
	this->rightText = new Text(fontFilePath);

	this->initTextures();
	
	const int heart_offset = 40;
	for (int i = 0; i < 4; ++i) {
		hearts[i] = new sf::Sprite(*lifeTexture);
		hearts[i]->setScale(0.1f, 0.1f);
		if (i <= 1) { // upper row
			hearts[i]->setPosition(362 + i * 40.0, 10);
		}
		else {
			hearts[i]->setPosition(362 + (i - 2) * 40.0, 50);
		}
		
		if (lives < i + 1) {
			hearts[i]->setTexture(*depletedLifeTexture);
		}
	}
}

UI::~UI()
{
}

void UI::initTextures()
{
	this->backgroundTexture = new sf::Texture();
	this->backgroundTexture->loadFromFile("tekstury/ui.png");
	this->uiBackground = new Background(this->backgroundTexture, 0, 0);
	this->uiBackground->setSize(backgroundWidth, backgroundHeight);
	this->lifeTexture = new sf::Texture();
	this->lifeTexture->loadFromFile("tekstury/heart.png");
	this->depletedLifeTexture = new sf::Texture();
	this->depletedLifeTexture->loadFromFile("tekstury/heart_lost.png");
}

void UI::toggleTimeScore()
{
}

void UI::update()
{
	


	smallLeftText->setParameters("Score:", 28, sf::Color::White, 20, backgroundHeight / 2 - 28 / 2 - 8);
	leftText->setParameters(std::to_string(score), 36, sf::Color::White, 110, backgroundHeight / 2 - 36 / 2 - 8);

	smallRightText->setParameters("Difficulty:", 28, sf::Color::White, 490, backgroundHeight / 2 - 28 / 2 - 8);

	if (difficulty == Easy) {
		rightText->setParameters("Easy", 36, sf::Color::White, 625, backgroundHeight / 2 - 36 / 2 - 8);
	}
	if (difficulty == Normal) {
		rightText->setParameters("Normal", 36, sf::Color::White, 625, backgroundHeight / 2 - 36 / 2 - 8);
	}
	if (difficulty == Hard) {
		rightText->setParameters("Hard", 36, sf::Color::White, 625, backgroundHeight / 2 - 36 / 2 - 8);
	}
	if (difficulty == Very_hard) {
		rightText->setParameters("Very hard", 36, sf::Color::White, 625, backgroundHeight / 2 - 36 / 2 - 8);
	}
	
}

void UI::render(sf::RenderTarget* target)
{
	this->uiBackground->render(target);

	for (size_t i = 0; i < 4; i++)
	{
		target->draw(*hearts[i]);
	}

	smallLeftText->render(target);
	leftText->render(target);
	smallRightText->render(target);
	rightText->render(target);

	
}

void UI::setScore(sf::Uint64 score)
{
	this->score = score;
}

sf::Uint64 UI::getScore()
{
	return this->score;
}

void UI::setDifficulty(Difficulty difficulty)
{
	this->difficulty = difficulty;
}

UI::Difficulty UI::getDifficulty()
{
	return this->difficulty;
}
