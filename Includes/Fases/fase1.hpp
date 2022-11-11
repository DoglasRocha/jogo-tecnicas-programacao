#pragma once
#include "fase.hpp"

using fases::Fase;

class Fase1 : public Fase
{
public:
    Fase1(Jogador *ptrJogador=nullptr);
    ~Fase1();
};