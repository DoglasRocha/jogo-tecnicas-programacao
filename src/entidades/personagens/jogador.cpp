#include "../../../Includes/Entidades/Personagens/jogador.hpp"

using entidades::personagens::Jogador;

entidades::personagens::Jogador::Jogador() {
    sentido = "DIREITA";
    num_vidas = 100;
    ataque = 20;

    carregarTexturas("Sprites/cj/cjandar", 0, 6);
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
                velX = 4;
                break;

            case (Keyboard::Left):
                if (sentido != "ESQUERDA") {
                    sprite.scale(-1.f, 1);
                    sentido = "ESQUERDA";
                }
                velX = -4;
                break;

            case (Keyboard::Up):
                if (qtdPulos < 2)
                    empuxo = -5, qtdPulos++;
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

void Jogador::repelirX(int direcao) {
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
    velX *= 1.4;
}

void Jogador::reset() {
    num_vidas = 100;
    x = 700;
    y = 500;
    sprite.setPosition(x, y);
    ptrGG->centralizarJanela(x);
}