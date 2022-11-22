#pragma once
#include "personagem.hpp"
#include <SFML/Graphics.hpp>

using entidades::personagens::Personagem;
using namespace sf;

namespace entidades::personagens {
	class Jogador : public Personagem
	{
    private:
        RectangleShape barra;
        RectangleShape fundoBarra;
        int pontuacao = 0;

    public:
        Jogador();
        virtual ~Jogador();
        virtual void processarEventos(Event evento) = 0;
        void colideX();
        void moverX();
        void repelirX(const int direcao);
        void repelirY();
        void lentidao();
        void queimar();
        void reset();
        virtual void desenhaBarraVida() = 0;
        int getPontuacao();
        void ganhaPontuacao(int pont);
	};	
}
