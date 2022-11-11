#include "../Includes/ente.hpp"

Ente::Ente(GerenciadorGrafico *gG,GerenciadorEventos *gE, GerenciadorColisoes *gC)
{
    gerenciadorGrafico = gG;
    gerenciadorEventos = gE;
    gerenciadorColisoes = gC;
}

Ente::~Ente()
{

}

void Ente::executar()
{

}
