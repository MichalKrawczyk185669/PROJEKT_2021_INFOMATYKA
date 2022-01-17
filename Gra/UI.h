#pragma once
#include "Text.h"
#include "Background.h"
class UI
{
public:
	enum Difficulty {
		Easy, Normal, Hard, Very_hard
	};
private:

	sf::Uint64 score = 0;
	Difficulty difficulty = Normal;
	sf::Uint64 timeElapsed;
	sf::Uint32 lives = 4;

	bool showingPauseScreen = false;
	bool showingExitScreen = false;
	bool showingHelpScreen = false;
	bool showingMainMenuScreen = true;
	bool showingLoadScreen = false;
	bool showingDeathScreen = false;

	bool startGameCall = false;
	bool exitGameCall = false;
	bool saveGameCall = false;
	bool loadGameCall[5] = {false};

	sf::Sprite* hearts[4];

	const float backgroundWidth = 800.f;
	const float backgroundHeight = 100.f;
	const int heartOffset = 40;

	Background* uiBackground;

	sf::Texture* backgroundTexture;
	sf::Texture* lifeTexture;
	sf::Texture* depletedLifeTexture;


	Text* smallLeftText;
	Text* smallRightText;

	Text* leftText;
	Text* rightText;

	bool showingScore;

	Text* menuTitle;
	Text* menuPlay;
	Text* menuLoad;
	Text* menuExit;

	sf::Shape* pauseBackground;
	Text* pauseTitle;

	Text* pauseToggle;
	sf::Shape* pauseToggleBox;
	Text* pauseHelp;
	sf::Shape* pauseHelpBox;
	Text* pauseExit;
	sf::Shape* pauseExitBox;
	Text* pauseSave;

	sf::Shape* blackScreenBackground;
	Text* exitTitle;
	Text* exitCancel;
	Text* exitConfirm;

	Text* helpText;
	Text* helpControls;
	Text* helpBack;
	
	Text* deathTitle;
	Text* deathBack;
	Text* deathExit;

	Text* loadTitle;
	Text* loadOptions[5];
	int* lastLoadFiles;
	Text* loadBack;
	bool loadFilesCall = true;

public:

	UI(std::string fontFilePath);
	~UI();

	void initTextures();

	void toggleTimeScore();

	void update();
	void render(sf::RenderTarget* target, sf::RenderWindow* window);

	void setScore(sf::Uint64 score);
	sf::Uint64 getScore();

	void setDifficulty(Difficulty difficulty);
	Difficulty getDifficulty();

	float getBackgroundHeight();

	void setLives(sf::Uint32 lives);
	sf::Uint32 getLives() const;

	void togglePauseScreen();

	bool getExitGameCall() const;

	bool getSaveGameCall() const;
	void setSaveGameCall(bool setSave);

	bool getLoadFilesCall() const;
	void setLoadFilesCall(bool setSave);

	bool getLoadGameCall(int index) const;
	void setLoadGameCall(bool setSave, int index);


	bool getStartGameCall();
	void setStartGameCall(bool setStart);

	void toggleHelpScreen();
	
	void setLastLoadFiles(int* lastLoadFiles);

	bool getMainMenuShown() const;

	void setDeathScreenShow(bool setDeath);
	
};

