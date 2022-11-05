#pragma once
#include "../entidade.hpp"
#include "../../listas/lista_texturas.hpp"
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
        ListaTexturas listaTexturas;
        ListaTexturas::Node *noAtual;
        std::string sentido;
        Clock relogioAnimacao;
        const sf::Time tempoAnimacao;

    public:
        Personagem();
        virtual ~Personagem();
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
        void escalarSprite(float fatorX, float fatorY);
        void animar();
        void resetAnimacao();
    };
}
