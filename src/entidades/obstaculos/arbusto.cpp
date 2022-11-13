#include "../../../Includes/Entidades/Obstaculos/arbusto.hpp"

Arbusto::Arbusto()
{
    altura = (float(rand())/RAND_MAX) + 1;
}

Arbusto::~Arbusto(){}

float Arbusto::getAltura() const
{
    return altura;
}