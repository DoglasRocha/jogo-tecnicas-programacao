#pragma once
#include "./Entidades/entidade.hpp"
#include <string>
using entidades::Entidade;
using namespace std;
using namespace sf;

class Botao : public Entidade
{
    private:
        const int tamX, tamY;
        Shape *shape;
        Texture *textura;

    public:
        Botao();
        Botao(const int posY, const string texturastring);
        ~Botao();
        void executar();
        void processarEventos(Event evento);
        Drawable *getDraw();
        Shape *getShape();
        void desenhar();
        void setEmpuxo(const int novoEmpuxo); 
};