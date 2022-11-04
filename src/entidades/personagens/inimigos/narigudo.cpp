#include "../../../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
#include "../../../../Includes/Gerenciadores/gerenciador_grafico.hpp"
#include "../../../../Includes/listas/lista_circular.hpp"
#include <iostream>
#include <sstream>

using entidades::personagens::Narigudo;

Narigudo::Narigudo() :
entidades::personagens::Inimigo() {
    sentido = "ESQUERDA";

    carregarTexturas("Sprites/narigudo", 1, 3);
    noAtual = listaTexturas.begin();
    sprite.setTexture(*(noAtual->getDado()));
    x = y = 200;
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
                animar();
                velX = 1;
                break;

            case (Keyboard::A):
                if (sentido != "ESQUERDA") {
                    sprite.scale(-1.f, 1.f);
                    sentido = "ESQUERDA";
                }
                velX = -1;
                animar();
                break;
        }
    }

    else if (evento.type == Event::KeyReleased) {
        switch (evento.key.code)
        {
            case (Keyboard::D):
                velX = 0;
                resetAnimacao();
                break;

            case (Keyboard::A):
                velX = 0;
                resetAnimacao();
                break;

            case (Keyboard::W):
                resetAnimacao();
		        velY = 0;
                break;
        }
    }
}
