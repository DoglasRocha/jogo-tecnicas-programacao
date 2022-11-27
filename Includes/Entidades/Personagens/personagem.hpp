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
        int num_vidas, qtdPulos, ataque;
        bool vivo;
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
        void setQtdPulos(const int pulos);
        int getQtdPulos() const; 
        Drawable *getDraw();
        Sprite* getSprite();
        virtual void processarEventos(Event evento) = 0;
        std::string getSentido() const;
        void setSentido(const std::string novoSentido);
        void setOriginToCenter();
        void setEmpuxo(const int novoEmpuxo);
        void carregarTexturas(const std::string endereco, const int comeco, const int fim);
        void escalarSprite(const float fatorX, const float fatorY);
        void animar();
        void resetAnimacao();
        void desenhar();
        virtual void colideX() = 0;
        virtual void colideY();
        virtual int getAtaque();
        virtual void recebeAtaque(Personagem *personagem);
        void recebeAtaque(int dano);
        void checaVivo();
        bool getVivo() const;
        virtual void lentidao() = 0;
        virtual void queimar() = 0;
    };
}
