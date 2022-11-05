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
        int getTamX();
        void setTamX(int novoTamX);
        int getTamY();
        void setTamY(int novoTamY);
        Shape *getShape();
	};
}
