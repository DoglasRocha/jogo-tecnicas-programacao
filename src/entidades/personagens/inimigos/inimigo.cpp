#include "../../../../Includes/Entidades/Personagens/Inimigos/inimigo.hpp"
#include "../../../../Includes/Entidades/Personagens/personagem.hpp"

using entidades::personagens::Inimigo;

entidades::personagens::Inimigo::Inimigo() :
entidades::personagens::Personagem() {

}

Inimigo::Inimigo(const float tempoAtaqueMs) :
tempoAtaque(milliseconds(tempoAtaqueMs)),
entidades::personagens::Personagem()
{

}

entidades::personagens::Inimigo::~Inimigo() {
}

void entidades::personagens::Inimigo::lentidao(){

}

void entidades::personagens::Inimigo::queimar(){

}
