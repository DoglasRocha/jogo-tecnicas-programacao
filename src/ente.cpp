#include "../Includes/ente.hpp"

Ente::Ente()
{
    gerenciadorGrafico = GerenciadorGrafico::getGerenciadorGrafico();
    gerenciadorEventos = GerenciadorEventos::getInstance();
    gerenciadorColisoes = GerenciadorColisoes::getInstance();
}

Ente::~Ente()
{

}

void Ente::executar()
{

}
