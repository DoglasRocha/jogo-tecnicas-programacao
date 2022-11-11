#pragma once
#include "personagem.hpp"
#include <SFML/Graphics.hpp>

using entidades::personagens::Personagem;
using namespace sf;

namespace entidades::personagens {
	class Jogador : public Personagem
	{
    public:
        Jogador();
        ~Jogador();
        void desenhar(RenderWindow *window);
        void processarEventos(Event evento);
        void colideX();
	};	
}
