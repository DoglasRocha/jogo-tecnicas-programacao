#pragma once
#include "menu.hpp"
#include "Gerenciadores/gerenciador_colisoes.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"
#include "Entidades/Obstaculos/Fogo.hpp"
#include "Entidades/Obstaculos/Arbusto.hpp"
#include "Entidades/Personagens/jogador.hpp"
#include "Entidades/Personagens/Inimigos/narigudo.hpp"
#include "Entidades/Personagens/Inimigos/inimigo2.hpp"
#include "Fases/fase1.hpp"
#include "Fases/fase2.hpp"

using namespace Gerenciadores;
using namespace entidades::personagens;

class Jogo {
private:
	GerenciadorGrafico *gerenciadorGrafico;
    GerenciadorColisoes *gerenciadorColisoes;
    GerenciadorEventos *gerenciadorEventos;
    Narigudo narigudo;
    Jogador cj;

public:
	Jogo();
	~Jogo();
};
