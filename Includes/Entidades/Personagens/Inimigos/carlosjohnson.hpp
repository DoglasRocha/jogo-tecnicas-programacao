#pragma once
#include "inimigo.hpp"

using namespace sf;

namespace entidades::personagens::inimigos {
    class CarlosJohnson : public Inimigo
    {
    private:
        Texture textura;
        std::string sentido;

    public:
        CarlosJohnson();
        ~CarlosJohnson();
        void desenhar(RenderWindow *window);
        void processarEventos(Event evento);
    };
}
