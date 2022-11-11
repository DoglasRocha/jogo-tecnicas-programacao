#pragma once
#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Gerenciadores/gerenciador_colisoes.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"
#include "background_manager.hpp"

using namespace Gerenciadores;

class Ente
{
    protected:
        int id;
        GerenciadorColisoes *gerenciadorColisoes;
        GerenciadorGrafico *gerenciadorGrafico;
        GerenciadorEventos *gerenciadorEventos;
        BackgroundManager *planoDeFundo;

    public:
        Ente();
        virtual ~Ente();
        virtual void executar();
        virtual void desenhar(GerenciadorGrafico *gG) = 0;
};
