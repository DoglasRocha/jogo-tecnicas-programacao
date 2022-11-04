#include "../../../Includes/Entidades/Personagens/personagem.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

using namespace sf;

entidades::personagens::Personagem::Personagem() {
    velX = velY = qtdPulos = empuxo = 0;
}

entidades::personagens::Personagem::~Personagem() {

}

void entidades::personagens::Personagem::moverX() {
    sprite.move((float)velX, 0.f);
    x += velX;
}

void entidades::personagens::Personagem::moverY() {
    sprite.move(0.f, (float)velY);
    y += velY;
}

void entidades::personagens::Personagem::setVelX(int novaVel) {
    velX = novaVel;
}

void entidades::personagens::Personagem::setVelY(int novaVel) {
    velY = novaVel;
}

int entidades::personagens::Personagem::getVelX() {
    return velX;
}

int entidades::personagens::Personagem::getVelY() {
    return velY;
}

Sprite *entidades::personagens::Personagem::getSprite() {
    return &sprite;
}

std::string entidades::personagens::Personagem::getSentido() {
    return sentido;
}

void entidades::personagens::Personagem::setSentido(std::string novoSentido) {
    sentido = novoSentido;
}

void entidades::personagens::Personagem::setOriginToCenter() {
    FloatRect bounds = sprite.getGlobalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    sprite.setPosition(x + bounds.width / 2, y + bounds.height / 2);
}

void entidades::personagens::Personagem::setQtdPulos(int pulos) {
    qtdPulos = pulos;
}

int entidades::personagens::Personagem::getQtdPulos() {
    return qtdPulos;
}

void entidades::personagens::Personagem::setEmpuxo(int novoEmpuxo) {
    if (empuxo < 0)
        empuxo = novoEmpuxo;
}

void entidades::personagens::Personagem::carregarTexturas(std::string endereco, int comeco, int fim) {
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

void entidades::personagens::Personagem::escalarSprite(int fatorX, int fatorY) {
    sprite.scale(fatorX, fatorY);
    FloatRect bounds = sprite.getGlobalBounds();
    x = bounds.left;
    y = bounds.top;
}