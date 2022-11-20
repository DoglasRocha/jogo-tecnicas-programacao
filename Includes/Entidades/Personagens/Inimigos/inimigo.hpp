#pragma once
#include "../personagem.hpp"
#include <SFML/Graphics.hpp>
#include "../../../listas/lista_circular.hpp"

using namespace sf;

namespace entidades::personagens
{
    class Inimigo : public Personagem
    {
    protected:
        int pontos;
        Clock relogioAtaque;
        const sf::Time tempoAtaque;
    public:
        Inimigo();
        Inimigo(const float tempoAtaqueMs);
        virtual ~Inimigo();
        virtual void processarEventos(Event evento) = 0;
        virtual void colideX() = 0;
        void lentidao();
        void queimar();
        int getPontos();
	};
}
