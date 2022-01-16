#include "UI.h"
#include <iostream>

UI::UI(std::string fontFilePath)
{
	this->smallLeftText = new Text(fontFilePath);
	this->leftText = new Text(fontFilePath);
	this->smallRightText = new Text(fontFilePath);
	this->rightText = new Text(fontFilePath);

	this->initTextures();
	
	this->pauseBackground = new sf::RectangleShape(sf::Vector2f(800, 600));
	this->pauseBackground->setFillColor(sf::Color(16, 16, 16, 160));

	this->pauseTitle = new Text(fontFilePath);
	this->pauseToggle = new Text(fontFilePath);
	this->pauseHelp = new Text(fontFilePath);
	this->pauseExit = new Text(fontFilePath);
	this->pauseToggle->getText()->setOutlineColor(sf::Color(10, 10, 10, 100));
	this->pauseHelp->getText()->setOutlineColor(sf::Color(10, 10, 10, 100));
	this->pauseExit->getText()->setOutlineColor(sf::Color(10, 10, 10, 100));


	this->pauseExitBox = new sf::RectangleShape(sf::Vector2f(1, 1));
	this->pauseToggleBox = new sf::RectangleShape(sf::Vector2f(1, 1));
	this->pauseHelpBox = new sf::RectangleShape(sf::Vector2f(1, 1));
	this->pauseExitBox->setFillColor(sf::Color::Transparent);
	this->pauseHelpBox->setFillColor(sf::Color::Transparent);
	this->pauseToggleBox->setFillColor(sf::Color::Transparent);
	this->pauseExitBox->setOutlineColor(sf::Color::White);
	this->pauseHelpBox->setOutlineColor(sf::Color::White);
	this->pauseToggleBox->setOutlineColor(sf::Color::White);

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
	

	for (int i = 0; i < 4; ++i) {
		hearts[i] = new sf::Sprite(*lifeTexture);
		hearts[i]->setScale(0.1f, 0.1f);
		if (i <= 1) { // upper row
			hearts[i]->setPosition(362 + i * heartOffset, 10);
		}
		else {
			hearts[i]->setPosition(362 + (i - 2) * heartOffset, 50);
		}

		if (lives < i + 1) {
			hearts[i]->setTexture(*depletedLifeTexture);
		}
	}

	if (showingPauseScreen) {
		pauseTitle->setParameters("Paused", 64, sf::Color::White, 400 - pauseTitle->getText()->getGlobalBounds().width / 2, 100);

		pauseToggle->setParameters("Toggle difficulty", 48, sf::Color::White, 400 - pauseToggle->getText()->getGlobalBounds().width / 2, 220);
		pauseExit->setParameters("Exit the game", 48, sf::Color::White, 400 - pauseExit->getText()->getGlobalBounds().width / 2, 420);
		pauseHelp->setParameters("Help", 48, sf::Color::White, 400 - pauseHelp->getText()->getGlobalBounds().width / 2, 320);

		pauseToggle->getText()->setString(pauseToggle->getText()->getString() + ": " + rightText->getText()->getString());


		
		
		
	}
}

void UI::render(sf::RenderTarget* target, sf::RenderWindow* window)
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

	if (showingPauseScreen) {
		target->draw(*this->pauseBackground);
		pauseTitle->render(target);

		pauseToggle->render(target);
		pauseHelp->render(target);
		pauseExit->render(target);

		if (pauseToggle->isHovering(window)) {
			pauseToggle->getText()->setOutlineThickness(5.0);
		}
		else {
			pauseToggle->getText()->setOutlineThickness(0);
		}
		if (pauseExit->isHovering(window)) {
			pauseExit->getText()->setOutlineThickness(5.0);
		}
		else {
			pauseExit->getText()->setOutlineThickness(0);
		}
		if (pauseHelp->isHovering(window)) {
			pauseHelp->getText()->setOutlineThickness(5.0);
		}
		else {
			pauseHelp->getText()->setOutlineThickness(0);
		}


		if (pauseToggle->handleClicks(window)) {
			difficulty = (Difficulty)((int)difficulty + 1);
			if ((int)difficulty == 4) {
				difficulty = (Difficulty)(0);
			}
		}
		if (pauseHelp->handleClicks(window)) {

		}
		if (pauseExit->handleClicks(window)) {

		}
	}
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

float UI::getBackgroundHeight()
{
	return backgroundHeight;
}

void UI::setLives(sf::Uint32 lives)
{
	this->lives = lives;
}

sf::Uint32 UI::getLives() const
{
	return this->lives;
}

void UI::togglePauseScreen()
{
	showingPauseScreen = !showingPauseScreen;
}
