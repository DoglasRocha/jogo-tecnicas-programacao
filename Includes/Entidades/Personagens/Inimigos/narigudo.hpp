#pragma once
#include "inimigo.hpp"
#include "../../../listas/lista_circular.hpp"
#include <string>
using namespace entidades::personagens::inimigos;
using namespace sf;
using Listas::ListaCircular;

namespace entidades::personagens::inimigos
{
    class Narigudo : public Inimigo
    {
    private:
        ListaCircular<Texture> listaTexturas;
        ListaCircular<Texture>::Node *noAtual;

    public:
        Narigudo();
        ~Narigudo();
        void desenhar(RenderWindow *window);
        void processarEventos(Event evento);
    };
}
