#pragma once
#include "../personagem.hpp"
#include <SFML/Graphics.hpp>

namespace entidades::personagens::inimigos
{
    class Inimigo : public Personagem
    {
    public:
        Inimigo();
        virtual ~Inimigo();
    	void setSprite(sf::Texture textura);
        virtual void desenhar(RenderWindow *window) = 0;
        virtual void processarEventos(Event evento) = 0;
	};
}
