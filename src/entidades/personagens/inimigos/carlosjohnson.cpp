#include "../../../../Includes/Entidades/Personagens/Inimigos/carlosjohnson.hpp"

entidades::personagens::inimigos::CarlosJohnson::CarlosJohnson() :
entidades::personagens::inimigos::Inimigo() {
    sentido = "ESQUERDA";

    listaTexturas.
        append(new Texture())->
        append(new Texture())->
        append(new Texture())->
        append(new Texture());

    noAtual = listaTexturas.begin();
    noAtual->getDado()->loadFromFile("texturas/cj.png");
    noAtual = noAtual->getNext();
    noAtual->getDado()->loadFromFile("texturas/cj2.png");
    noAtual = noAtual->getNext();
    noAtual->getDado()->loadFromFile("texturas/cj3.png");
    noAtual = noAtual->getNext();
    noAtual->getDado()->loadFromFile("texturas/cj2.png");
    noAtual = noAtual->getNext();
    sprite.setTexture(*noAtual->getDado());

    sprite.setPosition(400, 400);
    setOriginToCenter();
}

entidades::personagens::inimigos::CarlosJohnson::~CarlosJohnson() {
    ListaCircular<Texture>::Node *tmp;
    for (noAtual = listaTexturas.begin(); noAtual != listaTexturas.end(); noAtual = tmp) {
        tmp = noAtual->getNext();
        delete noAtual->getDado();
    }
    delete noAtual->getDado();
}

void entidades::personagens::inimigos::CarlosJohnson::desenhar(RenderWindow *window) {
    window->draw(sprite);
}

void entidades::personagens::inimigos::CarlosJohnson::processarEventos(Event evento) {
    if (evento.type == Event::KeyPressed)
    {
        switch (evento.key.code)
        {
            case (Keyboard::Right):
                if (sentido != "DIREITA") {
                    sprite.scale(-1.f, 1);
                    sentido = "DIREITA";
                }
                animar();
                velX = 1;
                break;

            case (Keyboard::Left):
                if (sentido != "ESQUERDA") {
                    sprite.scale(-1.f, 1);
                    sentido = "ESQUERDA";
                }
                animar();
                velX = -1;
                break;

            case (Keyboard::Up):
                if (velY >= 0 && qtdPulos < 2)
                    velY = -50, qtdPulos++;
		        animar();
                break;
        }
    }

    if (evento.type == Event::KeyReleased)
    {
        switch (evento.key.code)
        {
            case (Keyboard::Right):
                velX = 0;
                resetAnimacao();
                break;

            case (Keyboard::Left):
                resetAnimacao();
                velX = 0;
                break;

            case (Keyboard::Up):
		        resetAnimacao();
                velY = 0;
                break;

        }
    }
}
