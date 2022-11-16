#pragma once
#include "../estado.hpp"
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
    class Fase : public Ente, public Estado
    {
    protected:
        GerenciadorColisoes *gerenciadorColisoes;
        GerenciadorEventos *gerenciadorEventos;
        ListaEntidades listaDeEntidades;
        Jogador *ptrJogador;
        BackgroundManager *planoDeFundo;

    public:
        Fase(GerenciadorColisoes *gC=nullptr,
             GerenciadorEventos *gE=nullptr,
             Jogador *ptrJogador_=nullptr,
             Jogo *ptrJogo=nullptr);
        ~Fase();
        virtual void executar();
        virtual void processaEventos();
        void desenhar();
        void gerencia_colisoes();
        virtual void trocaEstado(int opcao=0) = 0;
        void criaPlataforma(int tamX, int tamY, int posX, int posY);
        void criaParede(int tamY, int posX, int posY);
        void criaNarigudo(int posX, int posY);
        void criaArbusto(int posX, int posY);
        void criaFogo(int posX, int posY);
        void criaPlataformaComAgregadosAleatorios(int tamX, int tamY, int posX, int posY, 
            bool geraNarigudo=true, bool geraArbusto=true, bool geraFogo=true);
    };
}
