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
        ListaEntidades listaDeEntidades;
        Jogador *ptrJogador;
        BackgroundManager *planoDeFundo;

    public:
        Fase(Jogador *ptrJogador_=nullptr);
        ~Fase();
        virtual void executar();
        virtual void processaEventos();
        void desenhar();
        void gerencia_colisoes();
    };
}
