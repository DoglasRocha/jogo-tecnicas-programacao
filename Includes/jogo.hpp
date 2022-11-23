#pragma once
#include "Entidades/Personagens/jogador1.hpp"
#include "Entidades/Personagens/jogador2.hpp"
#include "Gerenciadores/gerenciador_colisoes.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"

using namespace Gerenciadores;
using namespace entidades::personagens;

class Estado;

class Jogo {
private:
	GerenciadorGrafico *gerenciadorGrafico;
    GerenciadorColisoes *gerenciadorColisoes;
    GerenciadorEventos *gerenciadorEventos;
    Jogador1 cj;
    Jogador2 smoke;
    Estado *estadoAtual,
           *estadoAntigo;

public:
	Jogo();
	~Jogo();
    void irParaFase1(bool coop);
    void irParaFase2(bool coop);
    void irParaRanking();
    void irParaMenu();
    void irParaMenuJogadores(int fase);
};
