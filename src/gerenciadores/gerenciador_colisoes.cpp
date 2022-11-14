#include "../../Includes/Gerenciadores/gerenciador_colisoes.hpp"
#include "../../Includes/Gerenciadores/gerenciador_grafico.hpp"
#include <iostream>
#include <list>

using namespace sf;

namespace Gerenciadores
{

    GerenciadorColisoes::GerenciadorColisoes():gravidade(1) {

    }

    GerenciadorColisoes *GerenciadorColisoes::getInstance() {
        if (instance == nullptr)
            instance = new GerenciadorColisoes();

        return instance;
    }

    GerenciadorColisoes *GerenciadorColisoes::addInimigo(Inimigo *ptrInimigo) {
        vetorInimigos.push_back(ptrInimigo);
        return instance;
    }

    GerenciadorColisoes *GerenciadorColisoes::addObstaculo(Obstaculo *ptrObstaculo) {
        listaObstaculos.push_back(ptrObstaculo);
        return instance;
    }

    GerenciadorColisoes::~GerenciadorColisoes() {
        delete instance;
    }

    void GerenciadorColisoes::aplicaGravidade(Personagem *personagem)
    {
        personagem->setVelY(personagem->getVelY() + gravidade + personagem->getEmpuxo());
        personagem->setEmpuxo(personagem->getEmpuxo() + gravidade);
    }

    void GerenciadorColisoes::executar() {
        for (int i = 0, l = vetorInimigos.size(); i < l; i++) {
            moveX = moveY = true;
            executaColisoesObstaculos(vetorInimigos[i]);

            if (moveX) 
                vetorInimigos[i]->moverX();
            else
                vetorInimigos[i]->colideX();
            if (moveY)
                vetorInimigos[i]->moverY(),
                aplicaGravidade(vetorInimigos[i]);
            else
                vetorInimigos[i]->colideY();
        }
        executarColisoesJogador();
    }

    void GerenciadorColisoes::executarColisoesJogador() {
        moveX = moveY = true;
        executaColisoesObstaculos(jogador);
        executaColisaoJogadorComInimigo();
        if (moveX) 
            jogador->moverX();
        else
            jogador->colideX();
        if (moveY)
            jogador->moverY(),
            aplicaGravidade(jogador);
        else
            jogador->colideY();
    }

    void GerenciadorColisoes::executaColisoesObstaculos(Personagem *ptrPersonagem) {

        FloatRect bPersAtual = ptrPersonagem->getSprite()->getGlobalBounds(),
            bPersFuturo = bPersAtual;
        int deltaX = ptrPersonagem->getVelX(),
            deltaY = ptrPersonagem->getVelY() + ptrPersonagem->getEmpuxo();

        bPersFuturo.top += deltaY, bPersFuturo.left += deltaX;

        std::list<Obstaculo *>::iterator it;
        for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++) {
            FloatRect boundsObstaculo = (*it)->getShape()->getGlobalBounds();

            if (boundsObstaculo.intersects(bPersFuturo)) {
                bPersFuturo = bPersAtual;
                bPersFuturo.left += deltaX;
                if (boundsObstaculo.intersects(bPersFuturo)) {
                    moveX = false;
                }

                bPersFuturo = bPersAtual;
                bPersFuturo.top += deltaY;
                if (boundsObstaculo.intersects(bPersFuturo))
                    moveY = false;

            }
        }

        bPersFuturo.left += deltaX;
        //mostraHitbox(bPersFuturo.left, bPersFuturo.top, bPersFuturo.width, bPersFuturo.height);
    }

    void GerenciadorColisoes::mostraHitbox(int x, int y, int width, int height) {
        RectangleShape shape(Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(Color::White);

        GerenciadorGrafico::getInstance()->desenhaElemento(shape);
    }

    void GerenciadorColisoes::setJogador(Jogador *ptrJogador) {
        jogador = ptrJogador;
    }

    void GerenciadorColisoes::executaColisaoJogadorComInimigo() {

        FloatRect bJogador = jogador->getSprite()->getGlobalBounds(),
            bJogadorFuturo = bJogador;
        int deltaX = jogador->getVelX(),
            deltaY = jogador->getVelY() + jogador->getEmpuxo();

        bJogadorFuturo.top += deltaY, bJogadorFuturo.left += deltaX;

        for (int i = 0, l = vetorInimigos.size(); i < l; i++) {
            FloatRect boundsInimigo = vetorInimigos[i]->getSprite()->getGlobalBounds();

            if (boundsInimigo.intersects(bJogadorFuturo)) {
                bJogadorFuturo = bJogador;
                bJogadorFuturo.left += deltaX;
                if (boundsInimigo.intersects(bJogadorFuturo)) {
                    if (bJogadorFuturo.left < boundsInimigo.left)
                        jogador->repelirX(-1);
                    else
                        jogador->repelirX(1);

                    moveX = false;
                }
                
                bJogadorFuturo = bJogador;
                bJogadorFuturo.top += deltaY;
                if (boundsInimigo.intersects(bJogadorFuturo))
                    jogador->repelirY(), moveY = false;

            }
        }

        bJogadorFuturo.left += deltaX;
        //mostraHitbox(bJogadorFuturo.left, bJogadorFuturo.top, bJogadorFuturo.width, bJogadorFuturo.height);
    }
}
