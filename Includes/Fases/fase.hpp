#pragma once
#include "../ente.hpp"
#include "../Gerenciadores/gerenciador_colisoes.hpp"
#include "../Gerenciadores/gerenciador_grafico.hpp"
#include "../listas/lista_entidades.hpp"

using namespace Gerenciadores;
using Listas::ListaEntidades;

namespace fases
{
    class Fase : public Ente
    {
    protected:
        GerenciadorColisoes *gerenciadorColisoes;
        GerenciadorGrafico *gerenciadorGrafico;
        ListaEntidades listaDeEntidades;

    public:
        Fase(GerenciadorColisoes *gC=nullptr, GerenciadorGrafico *gG=nullptr);
        ~Fase();
        virtual void executar();
        void gerencia_colisoes();
    };
}
