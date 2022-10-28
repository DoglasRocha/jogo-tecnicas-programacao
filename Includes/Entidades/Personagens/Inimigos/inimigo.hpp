#pragma once
#include "../personagem.hpp"
#include <SFML/Graphics.hpp>

namespace entidades::personagens::inimigos
{
    class Inimigo : public Personagem
    {
    protected:
        sf::Sprite sprite;

    public:
    	void setSprite(sf::Texture textura);
	};
}
