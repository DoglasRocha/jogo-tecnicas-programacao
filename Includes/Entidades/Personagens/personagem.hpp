#pragma once
#include "../entidade.hpp"
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

namespace entidades::personagens
{
    class Personagem : public Entidade {
    protected:
        int num_vidas, hp, velX, velY;
        Sprite sprite;
        std::string sentido;

    public:
        Personagem();
        virtual ~Personagem();
        virtual void desenhar(RenderWindow *window) = 0;
        virtual void mover();
        void setVelX(int novaVel);
        void setVelY(int novaVel);
        int getVelX();
        int getVelY();
        Sprite *getSprite();
        virtual void processarEventos(Event evento) = 0;
        std::string getSentido();
        void setSentido(std::string novoSentido);
        void setOriginToCenter();
    };
}
