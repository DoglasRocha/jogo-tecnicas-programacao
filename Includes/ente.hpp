#pragma once
#include "Gerenciadores/gerenciador_grafico.hpp"

using Gerenciadores::GerenciadorGrafico;

class Ente
{
    protected:
        int id;

    public:
        Ente();
        virtual ~Ente();
        virtual void executar();
        virtual void desenhar(GerenciadorGrafico *gG) = 0;
};
