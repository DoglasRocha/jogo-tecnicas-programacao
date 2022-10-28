#pragma once
#include "inimigo.hpp"
#include <string>
using namespace entidades::personagens::inimigos;
using namespace sf;

namespace entidades::personagens::inimigos
{
    class Narigudo : public Inimigo
    {
    private:
        int frame, velX, velY;
        Texture texturas[3];
        Sprite sprite;
        std::string sentido;

    public:
        Narigudo();
        ~Narigudo();
        void desenhar(RenderWindow *window);
        void mover();
        void setVelX(int novaVel);
        void setVelY(int novaVel);
        int getVelX();
        int getVelY();
        std::string getSentido();
        void setSentido(std::string novoSentido);
        Sprite *getSprite();
    };
}
