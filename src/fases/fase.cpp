#include "../../Includes/Fases/fase.hpp"

using fases::Fase;

Fase::Fase(GerenciadorColisoes *gC, GerenciadorGrafico *gG)
{
    gerenciadorColisoes = gC;
    gerenciadorGrafico = gG;
}

Fase::~Fase()
{

}

void Fase::gerencia_colisoes()
{
	gerenciadorColisoes->executar();
}
