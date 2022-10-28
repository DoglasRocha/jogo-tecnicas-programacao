#pragma once
#include "../entidade.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

namespace entidades::personagens
{
    class Personagem : public Entidade {
    protected:
        int num_vidas, hp, velX, velY;
        Sprite sprite;

    public:
        Personagem();
        virtual ~Personagem();
        virtual void desenhar(RenderWindow *window) = 0;
        void mover();
        void setVelX(int novaVel);
        void setVelY(int novaVel);
        int getVelX();
        int getVelY();
        Sprite *getSprite();
        virtual void processarEventos(Event evento) = 0;
    };
}
