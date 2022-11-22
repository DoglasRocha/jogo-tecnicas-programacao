#include "../../../Includes/Entidades/Personagens/jogador1.hpp"

using namespace entidades::personagens;
using namespace sf;

Jogador1::Jogador1() : Jogador(){
    carregarTexturas("Sprites/cj/cjandar", 0, 6);
    noAtual = listaTexturas.begin();
    sprite.setTexture(*noAtual->getDado());
    x = 700, y = 500;
    setOriginToCenter();
    escalarSprite(3.0, 3.0);
}

Jogador1::~Jogador1(){
    
}

void Jogador1::processarEventos(Event evento) {
    if (evento.type == Event::KeyPressed)
    {
        switch (evento.key.code)
        {
            case (Keyboard::Right):
                if (sentido != "DIREITA") {
                    sprite.scale(-1.f, 1);
                    sentido = "DIREITA";
                }
                velX = 6;
                break;

            case (Keyboard::Left):
                if (sentido != "ESQUERDA") {
                    sprite.scale(-1.f, 1);
                    sentido = "ESQUERDA";
                }
                velX = -6;
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

void Jogador1::desenhaBarraVida(){
    RectangleShape barra(Vector2f(num_vidas * 2, 25));
    RectangleShape fundoBarra(Vector2f(200, 25));

    barra.setFillColor(Color::Green);
    fundoBarra.setFillColor(Color::Red);

    Vector2f posicaoView = ptrGG->getCentroView();
    barra.setPosition(posicaoView.x - 650, posicaoView.y - 450);
    fundoBarra.setPosition(posicaoView.x - 650, posicaoView.y - 450);
    barra.setSize(Vector2f(num_vidas*2, 25));

    ptrGG->desenhaElemento(fundoBarra);
    ptrGG->desenhaElemento(barra);
}