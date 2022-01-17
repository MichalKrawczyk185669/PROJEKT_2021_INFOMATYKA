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
	this->pauseSave = new Text(fontFilePath);
	this->pauseToggle->getText()->setOutlineColor(sf::Color(10, 10, 10, 100));
	this->pauseHelp->getText()->setOutlineColor(sf::Color(10, 10, 10, 100));
	this->pauseExit->getText()->setOutlineColor(sf::Color(10, 10, 10, 100));
	this->pauseSave->getText()->setOutlineColor(sf::Color(10, 10, 10, 100));

	this->menuTitle = new Text(fontFilePath);
	this->menuPlay = new Text(fontFilePath);
	this->menuExit = new Text(fontFilePath);
	this->menuLoad = new Text(fontFilePath);
	this->menuPlay->getText()->setOutlineColor(sf::Color(120, 120, 120, 100));
	this->menuLoad->getText()->setOutlineColor(sf::Color(120, 120, 120, 100));
	this->menuExit->getText()->setOutlineColor(sf::Color(120, 120, 120, 100));


	this->pauseExitBox = new sf::RectangleShape(sf::Vector2f(1, 1));
	this->pauseToggleBox = new sf::RectangleShape(sf::Vector2f(1, 1));
	this->pauseHelpBox = new sf::RectangleShape(sf::Vector2f(1, 1));
	this->pauseExitBox->setFillColor(sf::Color::Transparent);
	this->pauseHelpBox->setFillColor(sf::Color::Transparent);
	this->pauseToggleBox->setFillColor(sf::Color::Transparent);
	this->pauseExitBox->setOutlineColor(sf::Color::White);
	this->pauseHelpBox->setOutlineColor(sf::Color::White);
	this->pauseToggleBox->setOutlineColor(sf::Color::White);


	this->blackScreenBackground = new sf::RectangleShape(sf::Vector2f(800, 600));
	this->blackScreenBackground->setFillColor(sf::Color(0, 0, 0, 230));
	this->exitTitle = new Text(fontFilePath);
	this->exitCancel = new Text(fontFilePath);
	this->exitConfirm = new Text(fontFilePath);
	this->exitCancel->getText()->setOutlineColor(sf::Color(120, 120, 120, 100));
	this->exitConfirm->getText()->setOutlineColor(sf::Color(120, 120, 1120, 100));

	this->helpText = new Text(fontFilePath);
	this->helpBack = new Text(fontFilePath);
	this->helpControls = new Text(fontFilePath);
	this->helpBack->getText()->setOutlineColor(sf::Color(120, 120, 1120, 100));


	this->loadTitle = new Text(fontFilePath);
	for (int i = 0; i < 5; ++i) {
		this->loadOptions[i] = new Text(fontFilePath);
	}
	this->loadBack = new Text(fontFilePath);

	this->deathTitle = new Text(fontFilePath);
	this->deathExit = new Text(fontFilePath);
	this->deathExit->getText()->setOutlineColor(sf::Color(120, 120, 1120, 100));
	this->deathBack = new Text(fontFilePath);
	this->deathBack->getText()->setOutlineColor(sf::Color(120, 120, 1120, 100));
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

	if (showingMainMenuScreen) {
		menuTitle->setParameters("Smok wawelski i owce", 64, sf::Color::White, 400 - menuTitle->getText()->getGlobalBounds().width / 2, 40);
		menuPlay->setParameters("Play", 48, sf::Color::White, 400 - menuPlay->getText()->getGlobalBounds().width / 2, 140);
		menuLoad->setParameters("Load", 48, sf::Color::White, 400 - menuLoad->getText()->getGlobalBounds().width / 2, 240);
		menuExit->setParameters("Exit", 48, sf::Color::White, 400 - menuExit->getText()->getGlobalBounds().width / 2, 340);

		if (showingLoadScreen) {

			loadTitle->setParameters("Select load state", 48, sf::Color::White, 400 - loadTitle->getText()->getGlobalBounds().width / 2, 40);
			
			for (int i = 0; i < 5; i++) {
				if (lastLoadFiles[i] != -1) {
					loadOptions[i]->setParameters("Save" + std::to_string(lastLoadFiles[i]), 32, sf::Color::White, 400 - loadOptions[i]->getText()->getGlobalBounds().width / 2, 120 + 60 * i);
				}
			}
			loadBack->setParameters("Back", 44, sf::Color::White, 400 - loadBack->getText()->getGlobalBounds().width / 2, 440);
		}
	}

	if (showingDeathScreen) {
		deathTitle->setParameters("You died :(", 72, sf::Color::White, 400 - deathTitle->getText()->getGlobalBounds().width / 2, 100);
		deathBack->setParameters("Respawn", 64, sf::Color::White, 400 - deathBack->getText()->getGlobalBounds().width / 2, 220);
		deathExit->setParameters("Exit", 64, sf::Color::White, 400 - deathExit->getText()->getGlobalBounds().width / 2, 320);
	}

	if (showingPauseScreen) {
		pauseTitle->setParameters("Paused", 64, sf::Color::White, 400 - pauseTitle->getText()->getGlobalBounds().width / 2, 100);

		pauseToggle->setParameters("Toggle difficulty", 42, sf::Color::White, 400 - pauseToggle->getText()->getGlobalBounds().width / 2, 200);
		pauseExit->setParameters("Exit the game", 42, sf::Color::White, 400 - pauseExit->getText()->getGlobalBounds().width / 2, 440);
		pauseHelp->setParameters("Help", 42, sf::Color::White, 400 - pauseHelp->getText()->getGlobalBounds().width / 2, 280);
		pauseSave->setParameters("Save", 42, sf::Color::White, 400 - pauseSave->getText()->getGlobalBounds().width / 2, 360);

		pauseToggle->getText()->setString(pauseToggle->getText()->getString() + ": " + rightText->getText()->getString());

	}
	if (showingExitScreen) {
		exitCancel->setParameters("Cancel", 48, sf::Color::White, 400 - exitCancel->getText()->getGlobalBounds().width / 2, 240);
		exitTitle->setParameters("Are you sure you want to exit the game?", 40, sf::Color::White, 400 - exitTitle->getText()->getGlobalBounds().width / 2, 120);
		exitConfirm->setParameters("Exit the game", 48, sf::Color::White, 400 - exitConfirm->getText()->getGlobalBounds().width / 2, 340);
	}
	if (showingHelpScreen) {
		helpText->setParameters("The point of the game is to avoid the falling sheep \nand shoot them at the same time to gain points", 32, sf::Color::White, 40, 40);
		helpControls->setParameters("Controls:\nWASD - move the dragon\nLeft click and mouse position - shoot\nF1 - help menu\nEsc - pause game", 36, sf::Color::White, 40, 200);
		if (showingPauseScreen) {
			helpBack->setParameters("Cancel", 42, sf::Color::White, 400 - helpBack->getText()->getGlobalBounds().width / 2, 500);
		}
	}
}

void UI::render(sf::RenderTarget* target, sf::RenderWindow* window)
{
	if (showingMainMenuScreen) {
		target->draw(*this->pauseBackground);

		menuTitle->render(target);
		menuPlay->render(target);
		menuLoad->render(target);
		menuExit->render(target);

		if (menuPlay->isHovering(window) && !showingLoadScreen) {
			menuPlay->getText()->setOutlineThickness(5.0);
		}
		else {
			menuPlay->getText()->setOutlineThickness(0);
		}
		if (menuLoad->isHovering(window) && !showingLoadScreen) {
			menuLoad->getText()->setOutlineThickness(5.0);
		}
		else {
			menuLoad->getText()->setOutlineThickness(0);
		}
		if (menuExit->isHovering(window) && !showingLoadScreen) {
			menuExit->getText()->setOutlineThickness(5.0);
		}
		else {
			menuExit->getText()->setOutlineThickness(0);
		}


		if (menuPlay->handleClicks(window)) {
			showingMainMenuScreen = false;
			startGameCall = true;
		}
		if (menuLoad->handleClicks(window)) {
			showingLoadScreen = true;
			loadFilesCall = true;
			
		}
		if (menuExit->handleClicks(window)) {
			exitGameCall = true;
		}


		if (showingLoadScreen) {
			target->draw(*this->blackScreenBackground);
			loadTitle->render(target);
			for (int i = 0; i < 5; ++i) {
				loadOptions[i]->render(target);
			}
			loadBack->render(target);

			if (loadBack->isHovering(window)) {
				loadBack->getText()->setOutlineThickness(5.0);
			}
			else {
				loadBack->getText()->setOutlineThickness(0);
			}

			if (loadBack->handleClicks(window)) {
				showingLoadScreen = false;
			}

			for (int i = 0; i < 5; ++i) {
				if (loadOptions[i]->isHovering(window)) {
					loadOptions[i]->getText()->setOutlineThickness(5.0);
				}
				else {
					loadOptions[i]->getText()->setOutlineThickness(0);
				}

				if (loadOptions[i]->handleClicks(window)) {
					loadGameCall[i] = true;
					showingLoadScreen = false;
					showingMainMenuScreen = false;
				}
			}
		}
	}
	else {
		this->uiBackground->render(target);

		for (size_t i = 0; i < 4; i++)
		{
			target->draw(*hearts[i]);
		}

		smallLeftText->render(target);
		leftText->render(target);
		smallRightText->render(target);
		rightText->render(target);

		if (showingDeathScreen) {
			target->draw(*this->blackScreenBackground);
			deathTitle->render(target);
			deathBack->render(target);
			deathExit->render(target);

			if (deathBack->isHovering(window) && !showingExitScreen && !showingHelpScreen) {
				deathBack->getText()->setOutlineThickness(5.0);
			}
			else {
				deathBack->getText()->setOutlineThickness(0);
			}
			if (deathExit->isHovering(window) && !showingExitScreen && !showingHelpScreen) {
				deathExit->getText()->setOutlineThickness(5.0);
			}
			else {
				deathExit->getText()->setOutlineThickness(0);
			}


			if (deathBack->handleClicks(window) && !showingExitScreen && !showingHelpScreen) {
				this->startGameCall = true;
				this->showingDeathScreen = false;
			}
			if (deathExit->handleClicks(window) && !showingExitScreen && !showingHelpScreen) {
				this->showingExitScreen = true;
			}
		}

		if (showingPauseScreen) {
			target->draw(*this->pauseBackground);
			pauseTitle->render(target);

			pauseToggle->render(target);
			pauseHelp->render(target);
			pauseExit->render(target);
			pauseSave->render(target);

			if (pauseToggle->isHovering(window) && !showingExitScreen && !showingHelpScreen) {
				pauseToggle->getText()->setOutlineThickness(5.0);
			}
			else {
				pauseToggle->getText()->setOutlineThickness(0);
			}
			if (pauseExit->isHovering(window) && !showingExitScreen && !showingHelpScreen) {
				pauseExit->getText()->setOutlineThickness(5.0);
			}
			else {
				pauseExit->getText()->setOutlineThickness(0);
			}
			if (pauseHelp->isHovering(window) && !showingExitScreen && !showingHelpScreen) {
				pauseHelp->getText()->setOutlineThickness(5.0);
			}
			else {
				pauseHelp->getText()->setOutlineThickness(0);
			}
			if (pauseSave->isHovering(window) && !showingExitScreen && !showingHelpScreen) {
				pauseSave->getText()->setOutlineThickness(5.0);
			}
			else {
				pauseSave->getText()->setOutlineThickness(0);
			}


			if (pauseToggle->handleClicks(window) && !showingExitScreen && !showingHelpScreen) {
				difficulty = (Difficulty)((int)difficulty + 1);
				if ((int)difficulty == 4) {
					difficulty = (Difficulty)(0);
				}
			}
			if (pauseHelp->handleClicks(window)) {
				showingHelpScreen = true;
			}
			if (pauseExit->handleClicks(window)) {
				showingExitScreen = true;
			}
			if (pauseSave->handleClicks(window)) {
				saveGameCall = true;
			}
		}
		if (showingExitScreen) {
			target->draw(*blackScreenBackground);
			exitTitle->render(target);
			exitCancel->render(target);
			exitConfirm->render(target);

			if (exitCancel->isHovering(window)) {
				exitCancel->getText()->setOutlineThickness(5.0);
			}
			else {
				exitCancel->getText()->setOutlineThickness(0.0);
			}
			if (exitConfirm->isHovering(window)) {
				exitConfirm->getText()->setOutlineThickness(5.0);
			}
			else {
				exitConfirm->getText()->setOutlineThickness(0.0);
			}

			if (exitCancel->handleClicks(window)) {
				showingExitScreen = false;
			}

			if (exitConfirm->handleClicks(window)) {
				exitGameCall = true;
			}
		}
		if (showingHelpScreen) {
			target->draw(*blackScreenBackground);
			helpText->render(target);
			helpControls->render(target);

			if (showingPauseScreen) {
				helpBack->render(target);

				if (helpBack->isHovering(window)) {
					helpBack->getText()->setOutlineThickness(5.0);
				}
				else {
					helpBack->getText()->setOutlineThickness(0.0);
				}

				if (helpBack->handleClicks(window)) {
					showingHelpScreen = false;
				}
			}
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

bool UI::getExitGameCall() const
{
	return exitGameCall;
}

bool UI::getSaveGameCall() const
{
	return saveGameCall;
}

void UI::setSaveGameCall(bool setSave)
{
	this->saveGameCall = setSave;
}

bool UI::getLoadFilesCall() const
{
	return false;
}

void UI::setLoadFilesCall(bool setSave)
{
}

bool UI::getLoadGameCall(int index) const
{
	return loadGameCall[index];
}

void UI::setLoadGameCall(bool setSave, int index)
{
	this->loadGameCall[index] = setSave;
}

bool UI::getStartGameCall()
{
	return startGameCall;
}

void UI::setStartGameCall(bool setStart)
{
	this->startGameCall = setStart;
}

void UI::toggleHelpScreen()
{
	this->showingHelpScreen = !this->showingHelpScreen;
}

void UI::setLastLoadFiles(int* lastLoadFiles)
{
	this->lastLoadFiles = lastLoadFiles;
}

bool UI::getMainMenuShown() const
{
	return showingMainMenuScreen;
}

void UI::setDeathScreenShow(bool setDeath)
{
	this->showingDeathScreen = setDeath;
}
