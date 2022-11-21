#include "../../Includes/Entidades/projetil.hpp"

using entidades::Projetil;
using namespace std;

entidades::Projetil::Projetil(Minotauro* ptrMino_){
    ptrMino = ptrMino_;
    ataque = 10;
    sprite = new Sprite;
    textura = new Texture;
    textura->loadFromFile("texturas/projetil.png");
    sprite->setTexture(*textura);
    reset();
}

entidades::Projetil::~Projetil(){

}

void entidades::Projetil::moverX() {
    sprite->move((float)velX, 0.f);
    x += velX;
}

void entidades::Projetil::moverY() {
    sprite->move(0.f, (float)velY);
    y += velY;
}

void entidades::Projetil::setVelX(const int novaVel) {
    velX = novaVel;
}

void entidades::Projetil::setVelY(const int novaVel) {
    velY = novaVel;
}

int entidades::Projetil::getVelX() const {
    return velX;
}

int entidades::Projetil::getVelY() const {
    return velY;
}

Drawable* entidades::Projetil::getDraw(){
    return sprite;
}

Sprite* entidades::Projetil::getSprite(){
    return sprite;
}

int entidades::Projetil::getAtaque(){
    return ataque;
}

void entidades::Projetil::setEmpuxo(int novoEmpuxo){
    empuxo = novoEmpuxo;
}

void entidades::Projetil::reset(){
    sentido = ptrMino->getSentido();
    if(sentido == "ESQUERDA")
    {
        x = ptrMino->getX();
        velX = -12;
    }
    else 
    {
        x = ptrMino->getX() + 260;
        velX = 12;
    }
    y = ptrMino->getY() + 50;
    sprite->setPosition(x,y);
}

void entidades::Projetil::colideX(){
    reset();
}

void entidades::Projetil::colideY(){
    reset();
}

void entidades::Projetil::processarEventos(Event evento){

}

void entidades::Projetil::desenhar(){
    ptrGG->desenhaElemento(*sprite);
}

