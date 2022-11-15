#pragma once
#include "Entidades/Personagens/jogador.hpp"
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
    Jogador cj;
    Estado *estadoAtual;

public:
	Jogo();
	~Jogo();
    void irParaFase1();
    void irParaFase2();
    void irParaRanking();
    void irParaMenu();
};
