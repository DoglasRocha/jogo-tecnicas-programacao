#pragma once
#include "../personagem.hpp"
#include <SFML/Graphics.hpp>

namespace entidades 
{
	namespace personagens
	{
		namespace inimigos
		{
			class Inimigo : public Personagem
			{
				protected:
    			sf::Sprite sprite;

    			public:
    			virtual void setSprite(sf::Texture textura);
			};
		}
	}
}
