
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Przeciwnicy
{
private:
	sf::CircleShape shape;
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initShape();
	void initVariables();


	/*const sf::FloatRect getBounds() const;*/
	

public:
	Przeciwnicy(float pos_x, float pos_y);

	const sf::FloatRect getBounds() const;
	virtual ~Przeciwnicy();
	//funkcje
	void update();
	void render(sf::RenderTarget* target);

};

