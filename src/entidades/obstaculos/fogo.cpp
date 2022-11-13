#include "../../../Includes/Entidades/Obstaculos/fogo.hpp"

Fogo::Fogo()
{
    intensidade++; 
}

Fogo::~Fogo()
{
    intensidade = 0;
}

int Fogo::getIntensidade()
{
    return intensidade;
}