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
        ~Jogador();
        void processarEventos(Event evento);
        void colideX();
        void moverX();
        void repelirX(const int direcao);
        void repelirY();
        void lentidao();
        void queimar();
        void reset();
        void desenhaBarraVida();
        int getPontuacao();
        void ganhaPontuacao(int pont);
	};	
}
