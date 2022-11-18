#pragma once
#include "../ente.hpp"
#include <SFML/Graphics.hpp>
#include "../Gerenciadores/gerenciador_grafico.hpp"

using Gerenciadores::GerenciadorGrafico;

namespace entidades
{
    class Entidade : public Ente
    {
    protected:
        int empuxo, x, y;
    public:
        Entidade();
        virtual ~Entidade();
        virtual void executar();
        virtual void processarEventos(sf::Event evento) = 0;
        virtual void desenhar() = 0;
        int getEmpuxo() const;
        virtual void setEmpuxo(int novoEmpuxo) = 0;
        virtual sf::Drawable *getDraw() = 0;
        int getX() const;
        int getY() const;
        void setX(const int novoX);
        void setY(const int novoY);
    };
}
