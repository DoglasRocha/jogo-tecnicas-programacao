#pragma once
#include "inimigo.hpp"
#include "../../../listas/lista_circular.hpp"

using namespace sf;
using Listas::ListaCircular;

namespace entidades::personagens {
    class Minotauro : public Inimigo
    {
    private:
        int desgasteChifres;

    public:
        Minotauro();
        Minotauro(const int x, const int y);
        ~Minotauro();
        void processarEventos(Event evento);
        void colideX();
        void moverX();
        void lentidao();
        void queimar();
        int getAtaque();
        void setEmpuxo(const int novoEmpuxo);
    };
}