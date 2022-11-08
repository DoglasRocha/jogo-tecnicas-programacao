#pragma once
#include "ente.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"
#include "background_manager.hpp"

using namespace Gerenciadores;

class Menu : public Ente
{
    private:
        int cont = 1;
        GerenciadorGrafico *gerenciadorGrafico;
        GerenciadorEventos *gerenciadorEventos;
        BackgroundManager *planoDeFundo;

    public:
        Menu(GerenciadorGrafico *gG=nullptr, GerenciadorEventos *gE=nullptr);
        ~Menu();
        void executar();
        void processaEventos();
        void desenhar(GerenciadorGrafico *gG);
        void operator++();
        void operator--();
};
