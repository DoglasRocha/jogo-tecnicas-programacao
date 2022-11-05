#include "../../../Includes/Entidades/Personagens/jogador.hpp"

using entidades::personagens::Jogador;

entidades::personagens::Jogador::Jogador() {
    sentido = "DIREITA";

    carregarTexturas("Sprites/cjandar", 0, 6);
    noAtual = listaTexturas.begin();
    sprite.setTexture(*noAtual->getDado());
    x = 700, y = 500;
    setOriginToCenter();
    escalarSprite(3.0, 3.0);
}

entidades::personagens::Jogador::~Jogador() {
    ListaTexturas::Node *tmp;
    for (noAtual = listaTexturas.begin(); noAtual != listaTexturas.end(); noAtual = tmp) {
        tmp = noAtual->getNext();
        delete noAtual->getDado();
    }
    delete noAtual->getDado();
}

void entidades::personagens::Jogador::desenhar(RenderWindow *window) {

}

void entidades::personagens::Jogador::processarEventos(Event evento) {
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
                //animar();
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
        }
    }
}
