
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>


class KulaOgnia
{
   private:
	sf::Sprite shape;
	/*sf::Texture tekstura;*/

	sf::Vector2f direction;
	float szybkoscpocisku;
	/*void initTexture();
	void initSprite();*/
	public:
		
		KulaOgnia();
		KulaOgnia(sf::Texture* texture,float pos_x, float pos_y, float  dirx, float diry, float szbkosc_pocisku);
		
		virtual ~KulaOgnia();
        //kula
		const sf::FloatRect getBounds() const;

		void update();
		void render(sf::RenderTarget* target);


};


