#pragma once
#include "inimigo.hpp"
#include "../../../listas/lista_circular.hpp"

using namespace sf;
using Listas::ListaCircular;

namespace entidades::personagens {
    class Morcego : public Inimigo
    {
    private:
        int forcaAsas;

    public:
        Morcego();
        Morcego(int x, int y);
        ~Morcego();
        void processarEventos(Event evento);
        void colideX();
        void colideY();
        void moverY();
        void lentidao();
        void queimar();
        int getAtaque();
        void setEmpuxo(int novoEmpuxo);
        void setVelY(int novaVel);
    };
}
