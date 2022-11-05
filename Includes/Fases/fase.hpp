#pragma once
#include "../ente.hpp"
#include "../Gerenciadores/gerenciador_colisoes.hpp"
#include "../Gerenciadores/gerenciador_grafico.hpp"

using namespace Gerenciadores;

namespace fases
{
    class Fase : public Ente
    {
    protected:
        GerenciadorColisoes *gerenciadorColisoes;
        GerenciadorGrafico *gerenciadorGrafico;

    public:
        Fase(GerenciadorColisoes *gC=nullptr, GerenciadorGrafico *gG=nullptr);
        ~Fase();
        virtual void executar();
        void gerencia_colisoes();
    };
}
