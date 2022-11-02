#include "../../../../Includes/Entidades/Personagens/Inimigos/carlosjohnson.hpp"

entidades::personagens::CarlosJohnson::CarlosJohnson() :
entidades::personagens::Inimigo() {
    sentido = "DIREITA";

    carregarTexturas("Sprites/cjandar", 0, 6);
//    listaTexturas.
//        append(new Texture())->
//        append(new Texture())->
//        append(new Texture())->
//        append(new Texture());

    noAtual = listaTexturas.begin();
//    noAtual->getDado()->loadFromFile("texturas/cj.png");
//    noAtual = noAtual->getNext();
//    noAtual->getDado()->loadFromFile("texturas/cj2.png");
//    noAtual = noAtual->getNext();
//    noAtual->getDado()->loadFromFile("texturas/cj3.png");
//    noAtual = noAtual->getNext();
//    noAtual->getDado()->loadFromFile("texturas/cj2.png");
//    noAtual = noAtual->getNext();
    sprite.setTexture(*noAtual->getDado());

    sprite.scale(10, 10);
    sprite.setPosition(400, 400);
    x = y = 400;
    setOriginToCenter();
}

entidades::personagens::CarlosJohnson::~CarlosJohnson() {
    ListaCircular<Texture>::Node *tmp;
    for (noAtual = listaTexturas.begin(); noAtual != listaTexturas.end(); noAtual = tmp) {
        tmp = noAtual->getNext();
        delete noAtual->getDado();
    }
    delete noAtual->getDado();
}

void entidades::personagens::CarlosJohnson::desenhar(RenderWindow *window) {
    window->draw(sprite);
}

void entidades::personagens::CarlosJohnson::processarEventos(Event evento) {
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
                velX = 3;
                break;

            case (Keyboard::Left):
                if (sentido != "ESQUERDA") {
                    sprite.scale(-1.f, 1);
                    sentido = "ESQUERDA";
                }
                animar();
                velX = -3;
                break;

            case (Keyboard::Up):
                if (qtdPulos < 2)
                    empuxo = -5, qtdPulos++;
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
                break;

        }
    }
}

