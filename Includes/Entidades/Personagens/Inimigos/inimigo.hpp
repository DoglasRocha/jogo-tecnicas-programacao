#pragma once
#include "../personagem.hpp"
#include <SFML/Graphics.hpp>
#include "../../../listas/lista_circular.hpp"

namespace entidades::personagens
{
    class Inimigo : public Personagem
    {
    public:
        Inimigo();
        virtual ~Inimigo();
        virtual void processarEventos(Event evento) = 0;
	};
}
