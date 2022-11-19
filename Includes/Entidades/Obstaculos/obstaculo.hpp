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
        Obstaculo(const int tamX, const int tamY);
        Obstaculo(const int tamX, const int tamY, const int x, const int y);
        virtual ~Obstaculo();
        int getTamX() const;
        void setTamX(const int novoTamX);
        int getTamY() const;
        void setTamY(const int novoTamY);
        Drawable *getDraw();
        Shape *getShape();
        void desenhar();
        bool getAtravessar() const;
        virtual void interage(Personagem *ptrJogador) = 0;
	};
}
