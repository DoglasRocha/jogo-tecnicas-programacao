#pragma once
#include "inimigo.hpp"
#include "../../../listas/lista_circular.hpp"

using namespace sf;
using Listas::ListaCircular;

namespace entidades::personagens::inimigos {
    class CarlosJohnson : public Inimigo
    {

    public:
        CarlosJohnson();
        ~CarlosJohnson();
        void desenhar(RenderWindow *window);
        void processarEventos(Event evento);
    };
}
