#pragma once
#include "../entidade.hpp"
#include "../Personagens/jogador.hpp"

using entidades::Entidade;
using entidades::personagens::Personagem;
using namespace sf;

namespace entidades::obstaculos
{
	class Obstaculo : public Entidade
	{
    protected:
        int tamX, tamY;
        Shape *shape;
        Texture *textura;
        bool atravessavel = 0;

    public:
        Obstaculo();
        Obstaculo(int tamX, int tamY, int x, int y);
        virtual ~Obstaculo();
        int getTamX();
        void setTamX(int novoTamX);
        int getTamY();
        void setTamY(int novoTamY);
        Drawable *getDraw();
        Shape *getShape();
        void desenhar();
        bool getAtravessar();
        virtual void interage(Personagem *ptrJogador) = 0;
	};
}
