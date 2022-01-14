#pragma once
#include "Text.h"
#include "Background.h"
class UI
{
private:
	enum Difficulty {
		Easy, Normal, Hard, Very_hard
	};

	sf::Uint64 score = 123456789;
	Difficulty difficulty = Normal;
	sf::Uint64 timeElapsed;
	sf::Uint32 lives = 4;

	sf::Sprite* hearts[4];

	const float backgroundWidth = 800.f;
	const float backgroundHeight = 100.f;

	Background* uiBackground;

	sf::Texture* backgroundTexture;
	sf::Texture* lifeTexture;
	sf::Texture* depletedLifeTexture;


	Text* smallLeftText;
	Text* smallRightText;

	Text* leftText;
	Text* rightText;

	bool showingScore;

public:

	UI(std::string fontFilePath);
	~UI();

	void initTextures();

	void toggleTimeScore();

	void update();
	void render(sf::RenderTarget* target);

	void setScore(sf::Uint64 score);
	sf::Uint64 getScore();

	void setDifficulty(Difficulty difficulty);
	Difficulty getDifficulty();
};

