#include "../../../Includes/Entidades/Personagens/jogador.hpp"
#include <iostream>
using namespace std;

using entidades::personagens::Jogador;

entidades::personagens::Jogador::Jogador() {
    sentido = "DIREITA";
    num_vidas = 100;
    ataque = 20;

    font.loadFromFile("texturas/VCR_OSD_MONO.ttf");
}

entidades::personagens::Jogador::~Jogador() {
    
}

void entidades::personagens::Jogador::colideX() {
    velX = 0;
}

void entidades::personagens::Jogador::moverX() {
    sprite.move((float)velX, 0.f);
    x += velX;
    ptrGG->centralizarJanela(x);

    if (velX == 50 || velX == -50)
        velX = 0;
}

void Jogador::repelirX(const int direcao) {
    if (direcao < 0)
        velX = -50;
    else
        velX = 50;
}

void Jogador::repelirY() {
    empuxo = -6;
}

void Jogador::lentidao()
{
    velX *= 0.75;
}

void Jogador::queimar()
{
    num_vidas--;
    if(sentido == "ESQUERDA") velX = -9;
    else velX = 9;
}

void Jogador::reset() {
    num_vidas = 100;
    x = 700;
    y = 500;
    vivo = true;
    sprite.setPosition(x, y);
    ptrGG->centralizarJanela(x);
}

void Jogador::resetaPontuacao()
{
    pontuacao = 0;
}

int Jogador::getPontuacao()
{
    return pontuacao;
}

void Jogador::ganhaPontuacao(int pont)
{
    pontuacao += pont;
}