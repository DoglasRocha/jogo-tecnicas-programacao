#pragma once
#include "../personagem.hpp"
#include <SFML/Graphics.hpp>
#include "../../../listas/lista_circular.hpp"

namespace entidades::personagens
{
    class Inimigo : public Personagem
    {
    protected:
        sf::Clock relogioAnimacao;
        const sf::Time tempoAnimacao;
    public:
        Inimigo();
        virtual ~Inimigo();
    	void setSprite(sf::Texture textura);
        virtual void processarEventos(Event evento) = 0;
        void animar();
        void resetAnimacao();
	};
}
