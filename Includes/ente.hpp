#pragma once
#include "Gerenciadores/gerenciador_grafico.hpp"

using Gerenciadores::GerenciadorGrafico;

class Ente
{
    protected:
        int id;
        static GerenciadorGrafico *ptrGG;

    public:
        Ente();
        virtual ~Ente();
        virtual void executar() = 0;
        virtual void desenhar() = 0;
        static void setGerenciadorGrafico(GerenciadorGrafico *ptrGG);
};
