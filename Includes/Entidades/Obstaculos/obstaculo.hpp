#pragma once
#include "../entidade.hpp"

using entidades::Entidade;
using namespace sf;

namespace entidades::obstaculos
{
	class Obstaculo : public Entidade
	{
    protected:
        int tamX, tamY;
        Shape *shape;

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
	};
}
