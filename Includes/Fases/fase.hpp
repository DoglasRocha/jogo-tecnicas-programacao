#pragma once
#include "../ente.hpp"
#include "../Gerenciadores/gerenciador_colisoes.hpp"
#include "../Gerenciadores/gerenciador_grafico.hpp"
#include "../Gerenciadores/gerenciador_eventos.hpp"
#include "../listas/lista_entidades.hpp"
#include "../background_manager.hpp"

using namespace Gerenciadores;
using Listas::ListaEntidades;

namespace fases
{
    class Fase : public Ente
    {
    protected:
        GerenciadorColisoes *gerenciadorColisoes;
        GerenciadorGrafico *gerenciadorGrafico;
        GerenciadorEventos *gerenciadorEventos;
        ListaEntidades listaDeEntidades;
        Jogador *ptrJogador;
        BackgroundManager *planoDeFundo;

    public:
        Fase(GerenciadorColisoes *gC=nullptr,
             GerenciadorGrafico *gG=nullptr,
             GerenciadorEventos *gE=nullptr,
             Jogador *ptrJogador_=nullptr);
        ~Fase();
        virtual void executar() = 0;
        virtual void processaEventos();
        void desenhar(GerenciadorGrafico *gG);
        void gerencia_colisoes();
    };
}
