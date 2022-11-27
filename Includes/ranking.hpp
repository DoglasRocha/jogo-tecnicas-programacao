#pragma once
#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"
#include "Entidades/Personagens/jogador.hpp"
#include "background_manager.hpp"
#include "estado.hpp"
#include <vector>
#include <fstream>

using namespace Gerenciadores;
using namespace std;

struct infoJogador
{
    int pontos;
	string nome;
};

class Ranking : public Ente, public Estado
{
    private:
        GerenciadorEventos *gerenciadorEventos;
        BackgroundManager *planoDeFundo;
        Jogo *ptrJogo;
        Text titulo;
        Font font;
        vector<infoJogador> listaRanking;

    public:
        Ranking(GerenciadorEventos *gE=nullptr, Jogo *ptrJogo=nullptr);
        ~Ranking();
        void executar();
        void processaEventos();
        void desenhar();
        void trocaEstado(int opcao=0);
        void lerArquivo();
        void salvarArquivo(int pontos); 
        void escreveJogadores();
};