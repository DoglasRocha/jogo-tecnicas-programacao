#pragma once
#include "inimigo.hpp"
#include <string>
using namespace entidades::personagens::inimigos;
using namespace sf;

namespace entidades::personagens::inimigos
{
    class Narigudo : public Inimigo
    {
    private:
        int frame;
        Texture texturas[3];

    public:
        Narigudo();
        ~Narigudo();
        void desenhar(RenderWindow *window);
        void processarEventos(Event evento);
    };
}
