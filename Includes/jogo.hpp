#pragma once
#include "menu.hpp"
#include "Gerenciadores/gerenciador_colisoes.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Entidades/Obstaculos/obstaculoA.hpp"
#include "Entidades/Obstaculos/obstaculoB.hpp"
#include "Entidades/Personagens/jogador.hpp"
#include "Entidades/Personagens/Inimigos/narigudo.hpp"
#include "Entidades/Personagens/Inimigos/carlosjohnson.hpp"
#include "Fases/fase1.hpp"
#include "Fases/fase2.hpp"

using namespace Gerenciadores;
using namespace entidades::personagens;

class Jogo {
private:
	GerenciadorGrafico *janela;
    GerenciadorColisoes *gerenciadorColisoes;
    Narigudo narigudo;
    CarlosJohnson cj;

public:
	Jogo();
	~Jogo();
};
