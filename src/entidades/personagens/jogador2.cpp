#include "../../../Includes/Entidades/Personagens/jogador2.hpp"

using namespace entidades::personagens;
using namespace sf;

Jogador2::Jogador2() : Jogador(){
    carregarTexturas("Sprites/bigsmoke/bigsmokemoto", 0, 0);
    noAtual = listaTexturas.begin();
    sprite.setTexture(*noAtual->getDado());
    x = 700, y = 500;
    setOriginToCenter();
    escalarSprite(3.0, 3.0);
}

Jogador2::~Jogador2(){
    
}


void Jogador2::processarEventos(Event evento) {
    if (evento.type == Event::KeyPressed)
    {
        switch (evento.key.code)
        {
            case (Keyboard::D):
                if (sentido != "DIREITA") {
                    sprite.scale(-1.f, 1);
                    sentido = "DIREITA";
                }
                velX = 6;
                break;

            case (Keyboard::A):
                if (sentido != "ESQUERDA") {
                    sprite.scale(-1.f, 1);
                    sentido = "ESQUERDA";
                }
                velX = -6;
                break;

            case (Keyboard::W):
                if (qtdPulos < 2)
                    empuxo = -5, qtdPulos++;
                break;
        }
    }

    if (evento.type == Event::KeyReleased)
    {
        switch (evento.key.code)
        {
            case (Keyboard::D):
                velX = 0;
                resetAnimacao();
                break;

            case (Keyboard::A):
                resetAnimacao();
                velX = 0;
                break;
        }
    }
}

void Jogador2::desenhaBarraVida(){
    RectangleShape barra(Vector2f(num_vidas * 2, 25));
    RectangleShape fundoBarra(Vector2f(200, 25));

    barra.setFillColor(Color::Green);
    fundoBarra.setFillColor(Color::Red);

    Vector2f posicaoView = ptrGG->getCentroView();
    barra.setPosition(posicaoView.x +450, posicaoView.y - 450);
    fundoBarra.setPosition(posicaoView.x + 450, posicaoView.y - 450);
    barra.setSize(Vector2f(num_vidas*2, 25));

    ptrGG->desenhaElemento(fundoBarra);
    ptrGG->desenhaElemento(barra);
}

void Jogador2::moverX() {
    sprite.move((float)velX, 0.f);
    x += velX;

    if (velX == 50 || velX == -50)
        velX = 0;
}