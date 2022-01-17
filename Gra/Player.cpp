#include "Player.h"

void Player::initVariables()
{
	this->szybkoscporuszania = 2.f;
	this->attackCooldownMax = 12.f;
	this->attackCooldown = this->attackCooldownMax;
	this->facingRight = true;
	this->facingLeft = false;
}

void Player::initTexture()
{
	// za³adowanie tekstury z pliku
	if (!this->texture.loadFromFile("tekstury/trdragon.png"))
	{
		std::cout << "Blad:: Tekstura smoka nie moze byc zaladowana!" << "\n";
	}

	this->bodyTexture.loadFromFile("tekstury/trdragonbody.png");
	this->animatedBodyTexture.loadFromFile("tekstury/animated/dragonanimated.png");

	this->headTexture.loadFromFile("tekstury/trdragonhead.png");

	
}

void Player::initSprite()
{
	// ustawienie tekstury w sprajcie
	this->sprite.setTexture(this->texture);

	this->spriteBody.setTexture(this->animatedBodyTexture);
	this->spriteHead.setTexture(this->headTexture);
	
	animatedBodyRect.left = 0; animatedBodyRect.top = 0;
	animatedBodyRect.width = 650; animatedBodyRect.height = 730;

	spriteBody.setTextureRect(animatedBodyRect);


	spriteHead.scale(0.1f, 0.1f);
	spriteBody.scale(0.1f, 0.1f);
	spriteBody.setOrigin(this->getBounds().width / 2, 0.0f);
	spriteHead.setOrigin(this->getBounds().width / 2, 0.0f);

	//zmiana rozmiaru sprajta zeby pasowal do okna
	this->sprite.scale(0.1f, 0.1f);

	sprite.setOrigin(this->getBounds().width / 2, 0.0f);
}

void Player::initAnimation()
{
	this->playerAnimation = new Animation(300, 4);
}

Player::Player()
{
	/*this->szybkoscporuszania = 2.f;*/
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimation();
}

Player::~Player()
{

}

const::sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::FloatRect Player::getBodyBounds() const
{
	return this->spriteBody.getGlobalBounds();
}

const sf::FloatRect Player::getHeadBounds() const
{
	return this->spriteHead.getGlobalBounds();
}

void Player::setPosition(float posX, float posY)
{
	this->spriteBody.move(posX, posY);
}

void Player::move(const float dirX, const float dirY)
{
	//this->sprite.move(this->szybkoscporuszania * dirX, this->szybkoscporuszania * dirY);

	this->spriteHead.move(this->szybkoscporuszania * dirX, this->szybkoscporuszania * dirY);
	this->spriteBody.move(this->szybkoscporuszania * dirX, this->szybkoscporuszania * dirY);
	

}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.0f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if(this->attackCooldown< this->attackCooldownMax)
	  this->attackCooldown += 0.5f;

}

void Player::faceLeft() {
	facingLeft = true;
	facingRight = false;
}
void Player::faceRight() {
	facingRight = true;
	facingLeft = false;
}

sf::Vector2f* Player::getMouthPos() const
{
	if (facingRight) {
		return new sf::Vector2f(spriteHead.getGlobalBounds().left + spriteHead.getGlobalBounds().width,
			spriteHead.getGlobalBounds().top + spriteHead.getGlobalBounds().height / 2);
	}
	else {
		return new sf::Vector2f(spriteHead.getGlobalBounds().left - spriteBody.getGlobalBounds().width / 2 - 5.0, spriteHead.getGlobalBounds().top + spriteHead.getGlobalBounds().height / 2);
	}
}

//funkcje
void Player::update()
{

	spriteHead.setPosition(spriteBody.getGlobalBounds().left + spriteBody.getGlobalBounds().width + spriteHead.getGlobalBounds().width * 2 - 5,
		spriteBody.getGlobalBounds().top + spriteHead.getGlobalBounds().height - 5);

	this->updateAttack();

	if (facingLeft) {
		spriteBody.setScale(-0.1f, 0.1f);
		spriteHead.setScale(-0.1f, 0.1f);
		//sprite.setOrigin(sprite.getPosition().x + sprite.getLocalBounds().width / 4, sprite.getPosition().y - sprite.getLocalBounds().height / 4);
		//sprite.setScale(-0.1f, 0.1f);
		spriteHead.setPosition(spriteHead.getPosition().x - spriteBody.getGlobalBounds().width * 2 - spriteHead.getGlobalBounds().width,spriteHead.getPosition().y);
	}
	if (facingRight) {
		//sprite.setOrigin(sprite.getPosition().x + sprite.getLocalBounds().width / 4, sprite.getPosition().y - sprite.getLocalBounds().height / 4);
		//sprite.setScale(0.1f, 0.1f);

		//spriteHead.setPosition(spriteHead.getPosition().x + spriteBody.getGlobalBounds().width ,spriteHead.getPosition().y);

		spriteHead.setPosition(spriteBody.getGlobalBounds().left + spriteBody.getGlobalBounds().width + spriteHead.getGlobalBounds().width * 2 - 5,
			spriteBody.getGlobalBounds().top + spriteHead.getGlobalBounds().height - 5);

		spriteBody.setScale(0.1f, 0.1f);
		spriteHead.setScale(0.1f, 0.1f);
	}

	if (clock.getElapsedTime().asSeconds() > 0.5f) {
		spriteBody.setTextureRect(animatedBodyRect);
		animatedBodyRect.left += 650;

		if (animatedBodyRect.left == 2600) {
			animatedBodyRect.left = 0;
		}

		clock.restart();
	}

	//this->playerAnimation->update();
	//this->spriteBody.setTexture( *this->playerAnimation->getAnimatedTexture());
	//this->spriteHead.setTexture(*this->playerAnimation->getAnimatedTexture());
}

void Player::render(sf::RenderTarget& target)
{
	try
	{
		target.draw(this->spriteBody);
		target.draw(this->spriteHead);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	
}

bool Player::isRightFacing()
{
	return facingRight;
}

sf::Uint64 Player::getMiddlePos()
{
	return (spriteBody.getGlobalBounds().left + (spriteHead.getGlobalBounds().width + spriteBody.getGlobalBounds().width) / 2);
}
