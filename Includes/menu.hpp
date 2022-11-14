#pragma once
#include "ente.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"
#include "background_manager.hpp"
#include "botao.hpp"
#include "listas/lista_entidades.hpp"

using namespace Gerenciadores;
using namespace Listas;

class Menu : public Ente
{
    private:
        int cont = 1;
        GerenciadorEventos *gerenciadorEventos;
        BackgroundManager *planoDeFundo;
        ListaEntidades listaDeBotoes;

    public:
        Menu(GerenciadorEventos *gE=nullptr);
        ~Menu();
        void executar();
        void processaEventos();
        void desenhar();
        void resetaBotoes();
        void operator++();
        void operator--();
};
