#pragma once
#include "inimigo.hpp"
#include "../../../listas/lista_circular.hpp"

using namespace sf;
using Listas::ListaCircular;

namespace entidades::personagens
{
    class Narigudo : public Inimigo
    {
    private:
        int forcaEspirro;

    public:
        Narigudo();
        Narigudo(int x, int y);
        ~Narigudo();
        void processarEventos(Event evento);
        void colideX();
    };
}
