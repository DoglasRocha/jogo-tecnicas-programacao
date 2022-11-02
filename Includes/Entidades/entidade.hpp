#pragma once
#include "../base.hpp"
#include <SFML/Graphics.hpp>

namespace entidades
{
    class Entidade : public Base
    {
    protected:
        int empuxo, x, y;
    public:
        Entidade();
        ~Entidade();
        virtual void executar();
        virtual void desenhar(sf::RenderWindow *window) = 0;
        virtual void processarEventos(sf::Event evento) = 0;
        int getEmpuxo() const;
        virtual void setEmpuxo(int novoEmpuxo) = 0;
        int getX();
        int getY();
        void setX(int novoX);
        void setY(int novoY);
    };
}
