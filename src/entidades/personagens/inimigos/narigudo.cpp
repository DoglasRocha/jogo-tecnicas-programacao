#include "../../../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
#include "../../../../Includes/Gerenciadores/gerenciador_grafico.hpp"
#include "../../../../Includes/listas/lista_circular.hpp"
#include <iostream>

using entidades::personagens::inimigos::Narigudo;

Narigudo::Narigudo() :
entidades::personagens::inimigos::Inimigo() {
    sentido = "ESQUERDA";

    Texture *textura1 = new Texture(),
            *textura2 = new Texture(),
            *textura3 = new Texture();

    textura1->loadFromFile("texturas/narigudo.png");
    textura2->loadFromFile("texturas/narigudo2.png");
    textura3->loadFromFile("texturas/narigudo3.png");

    listaTexturas.
        append(textura1)->
        append(textura2)->
        append(textura3);

    noAtual = listaTexturas.end();

    sprite.setTexture(*(noAtual->getDado()));

    sprite.setPosition(200, 200);
    setOriginToCenter();
};

Narigudo::~Narigudo() {
    ListaCircular<Texture>::Node *tmp;
    for (noAtual = listaTexturas.begin(); noAtual != listaTexturas.end(); noAtual = tmp) {
        tmp = noAtual->getNext();
        delete noAtual->getDado();
    }
    delete noAtual->getDado();
}

void Narigudo::desenhar(RenderWindow *window) {
    window->draw(sprite);
    noAtual = noAtual->getNext();
    sprite.setTexture(*(noAtual->getDado()));
}

void Narigudo::processarEventos(Event evento) {
    if (evento.type == Event::KeyPressed) {
        switch (evento.key.code)
        {
            case (Keyboard::D):
                if (sentido != "DIREITA") {
                    sprite.scale(-1.f, 1.f);
                    sentido = "DIREITA";
                }
                velX = 1;
                break;

            case (Keyboard::A):
                if (sentido != "ESQUERDA") {
                    sprite.scale(-1.f, 1.f);
                    sentido = "ESQUERDA";
                }
                velX = -1;
                break;

            case (Keyboard::W):
                velY = -1;
                break;

            case (Keyboard::S):
                velY = 1;
                break;
        }
    }

    else if (evento.type == Event::KeyReleased) {
        switch (evento.key.code)
        {
            case (Keyboard::D):
                velX = 0;
                break;

            case (Keyboard::A):
                velX = 0;
                break;

            case (Keyboard::W):
                velY = 0;
                break;

            case (Keyboard::S):
                velY = 0;
                break;
        }
    }
}
