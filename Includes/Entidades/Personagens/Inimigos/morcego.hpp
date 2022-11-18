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
        Morcego(const int x, const int y);
        ~Morcego();
        void processarEventos(Event evento);
        void colideX();
        void colideY();
        void moverY();
        void lentidao();
        void queimar();
        int getAtaque() const;
        void setEmpuxo(const int novoEmpuxo);
    };
}
