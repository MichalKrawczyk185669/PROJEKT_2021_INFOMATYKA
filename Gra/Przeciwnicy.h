
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Przeciwnicy
{
private:
	sf::CircleShape shape;

	sf::Sprite* sprite;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::IntRect textureRect;

	int type;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initShape();
	void initVariables();


	/*const sf::FloatRect getBounds() const;*/
	

public:
	Przeciwnicy(sf::Texture* texture, float pos_x, float pos_y);

	const sf::FloatRect getBounds() const;
	virtual ~Przeciwnicy();
	//funkcje
	void update();
	void render(sf::RenderTarget* target);

};

