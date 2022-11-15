#pragma once
#include "inimigo.hpp"
#include "../../../listas/lista_circular.hpp"

using namespace sf;
using Listas::ListaCircular;

namespace entidades::personagens {
    class Inimigo2 : public Inimigo
    {

    public:
        Inimigo2();
        ~Inimigo2();
        void desenhar(RenderWindow *window);
        void processarEventos(Event evento);
        void colideX();
        void lentidao();
        void queimar();
    };
}
