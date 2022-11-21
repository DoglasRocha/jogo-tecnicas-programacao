#include "../../../Includes/Entidades/Personagens/personagem.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

using namespace sf;

entidades::personagens::Personagem::Personagem() :
tempoAnimacao(milliseconds(125)) {
    velX = velY = qtdPulos = empuxo = 0;
    vivo = true;
}

entidades::personagens::Personagem::~Personagem() {
    listaTexturas.limparLista();
}

void entidades::personagens::Personagem::moverX() {
    sprite.move((float)velX, 0.f);
    x += velX;
}

void entidades::personagens::Personagem::moverY() {
    sprite.move(0.f, (float)velY);
    y += velY;
}

void entidades::personagens::Personagem::setVelX(const int novaVel) {
    velX = novaVel;
}

void entidades::personagens::Personagem::setVelY(const int novaVel) {
    velY = novaVel;
}

int entidades::personagens::Personagem::getVelX() const {
    return velX;
}

int entidades::personagens::Personagem::getVelY() const {
    return velY;
}

std::string entidades::personagens::Personagem::getSentido() const {
    return sentido;
}

void entidades::personagens::Personagem::setSentido(const std::string novoSentido) {
    sentido = novoSentido;
}

void entidades::personagens::Personagem::setOriginToCenter() {
    FloatRect bounds = sprite.getGlobalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    sprite.setPosition(x + bounds.width / 2, y + bounds.height / 2);
}

void entidades::personagens::Personagem::setQtdPulos(const int pulos) {
    qtdPulos = pulos;
}

int entidades::personagens::Personagem::getQtdPulos() const {
    return qtdPulos;
}

void entidades::personagens::Personagem::setEmpuxo(const int novoEmpuxo) {
    if (empuxo < 0)
        empuxo = novoEmpuxo;
}

void entidades::personagens::Personagem::carregarTexturas(const std::string endereco, const int comeco, const int fim) {
    Texture *textura;

    for (int i = comeco; i <= fim; i++)
    {
        std::stringstream buffer;
        buffer << "texturas/" << endereco << i << ".png";
        textura = new Texture();
        if (!textura->loadFromFile(buffer.str()))
            std::cout << "Erro ao carregar textura" << std::endl;
        else
        {
            listaTexturas.append(textura);
        }
    }
}

void entidades::personagens::Personagem::escalarSprite(const float fatorX, const float fatorY) {
    sprite.scale(fatorX, fatorY);
    FloatRect bounds = sprite.getGlobalBounds();
    x = bounds.left;
    y = bounds.top;
}

void entidades::personagens::Personagem::animar() {
    if (relogioAnimacao.getElapsedTime() >= tempoAnimacao) {
        noAtual = noAtual->getNext();
        sprite.setTexture(*(noAtual->getDado()));
        relogioAnimacao.restart();
    }
}

void entidades::personagens::Personagem::resetAnimacao() {
    noAtual = listaTexturas.begin();
    sprite.setTexture(*(noAtual->getDado()));
}

Drawable *entidades::personagens::Personagem::getDraw() {
    return &sprite;
}

Sprite *entidades::personagens::Personagem::getSprite() {
    return &sprite;
}

void entidades::personagens::Personagem::desenhar() {
    if (!vivo) return;
    
    ptrGG->desenhaElemento(sprite);
    if (velX != 0)
        animar();
}

void entidades::personagens::Personagem::colideY() {
    velY = 0,
    qtdPulos = 0;
}

int entidades::personagens::Personagem::getAtaque() {
    return ataque;
}

void entidades::personagens::Personagem::recebeAtaque(Personagem *personagem) {
    num_vidas -= personagem->getAtaque();
    checaVivo();
}

void entidades::personagens::Personagem::recebeAtaque(int dano) {
    num_vidas -= dano;
    checaVivo();
}

void entidades::personagens::Personagem::checaVivo(){
    if (num_vidas <= 0) 
        vivo = false; 
}

bool entidades::personagens::Personagem::getVivo() const {
    return vivo;
}