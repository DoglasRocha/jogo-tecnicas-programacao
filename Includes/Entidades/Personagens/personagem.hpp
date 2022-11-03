#pragma once
#include "../entidade.hpp"
#include "../../listas/lista_circular.hpp"
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace Listas;

namespace entidades::personagens
{
    class Personagem : public Entidade {
    protected:
        int num_vidas, velX, velY, qtdPulos;
        Sprite sprite;
        ListaCircular<Texture> listaTexturas;
        ListaCircular<Texture>::Node *noAtual;
        std::string sentido;

    public:
        Personagem();
        virtual ~Personagem();
        virtual void desenhar(RenderWindow *window) = 0;
        virtual void moverX();
        virtual void moverY();
        void setVelX(int novaVel);
        void setVelY(int novaVel);
        int getVelX();
        int getVelY();
        void setQtdPulos(int pulos);
        int getQtdPulos();
        Sprite *getSprite();
        virtual void processarEventos(Event evento) = 0;
        std::string getSentido();
        void setSentido(std::string novoSentido);
        void setOriginToCenter();
        void setEmpuxo(int novoEmpuxo);
        void carregarTexturas(std::string endereco, int comeco, int fim);
    };
}
