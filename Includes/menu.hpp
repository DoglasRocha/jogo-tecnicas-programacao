#pragma once
#include "ente.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"
#include "background_manager.hpp"
#include "botao.hpp"
#include "listas/lista_entidades.hpp"
#include "estado.hpp"

using namespace Gerenciadores;
using namespace Listas;

class Menu : public Ente, public Estado
{
    private:
        int cont = 1;
        GerenciadorEventos *gerenciadorEventos;
        BackgroundManager *planoDeFundo;
        ListaEntidades listaDeBotoes;
        Jogo *ptrJogo;

    public:
        Menu(GerenciadorEventos *gE=nullptr, Jogo *ptrJogo=nullptr);
        ~Menu();
        void executar();
        void processaEventos();
        void desenhar();
        void resetaBotoes();
        void operator++();
        void operator--();
        void trocaEstado(int opcao=0);
};