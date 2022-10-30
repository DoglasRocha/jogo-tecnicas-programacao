#pragma once
#include "../entidade.hpp"
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

namespace entidades::personagens
{
    class Personagem : public Entidade {
    protected:
        int num_vidas, hp, velX, velY, qtdPulos;
        Sprite sprite;
        std::string sentido;

    public:
        Personagem();
        virtual ~Personagem();
        virtual void desenhar(RenderWindow *window) = 0;
        virtual void moverX();
        virtual void moverY();
        void setVelX(int novaVel);
        void setVelY(int novaVel);
        int getVelX();
        int getVelY();
        void setQtdPulos(int pulos);
        int getQtdPulos();
        Sprite *getSprite();
        virtual void processarEventos(Event evento) = 0;
        std::string getSentido();
        void setSentido(std::string novoSentido);
        void setOriginToCenter();
    };
}
