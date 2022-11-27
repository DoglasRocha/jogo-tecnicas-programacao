#pragma once
#include "personagem.hpp"
#include <SFML/Graphics.hpp>

using entidades::personagens::Personagem;
using namespace sf;

namespace entidades::personagens {
	class Jogador : public Personagem
	{
    private:
        int pontuacao = 0;

    public:
        Jogador();
        virtual ~Jogador();
        virtual void processarEventos(Event evento) = 0;
        void colideX();
        virtual void moverX();
        void repelirX(const int direcao);
        void repelirY();
        void lentidao();
        void queimar();
        void reset();
        virtual void desenhaBarraVida() = 0;
        void resetaPontuacao();
        int getPontuacao();
        void ganhaPontuacao(int pont);
	};	
}
