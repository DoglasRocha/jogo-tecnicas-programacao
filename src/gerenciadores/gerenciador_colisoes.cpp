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

    GerenciadorColisoes *GerenciadorColisoes::addInimigo(Personagem *ptrInimigo) {
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
        // colisao com tela
        executaColisoesObstaculos(jogador);
        for (int i = 0, l = vetorInimigos.size(); i < l; i++) {
            executaColisoesObstaculos(vetorInimigos[i]);
//            FloatRect boundsPersonagem = vetorInimigos[i]->getSprite()->getGlobalBounds();
//            int x = vetorInimigos[i]->getX() + vetorInimigos[i]->getVelX(),
//            y = vetorInimigos[i]->getY() + vetorInimigos[i]->getVelY() + vetorInimigos[i]->getEmpuxo();
//
//            // mostraHitbox(x, y, boundsPersonagem.width, boundsPersonagem.height);
//
//            if (y >= 0 &&
//                (y + boundsPersonagem.height) <= TAM_TELA[1])
//            {
//                aplicaGravidade(vetorInimigos[i]);
//                vetorInimigos[i]->moverY();
//            }
//            else
//            {
//                vetorInimigos[i]->setQtdPulos(0);
//                vetorInimigos[i]->setVelY(0);
//            }
//
//            if (x >= 0 &&
//                (x + boundsPersonagem.width) <= TAM_TELA[0])
//                vetorInimigos[i]->moverX();
        }
    }

    void GerenciadorColisoes::executaColisoesObstaculos(Personagem *ptrPersonagem) {
        bool moveX, moveY;
        moveX = moveY = true;

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
        // mostraHitbox(bPersFuturo.left, bPersFuturo.top, bPersFuturo.width, bPersFuturo.height);
        if (moveX) ptrPersonagem->moverX();
        if (moveY)
            ptrPersonagem->moverY(),
            aplicaGravidade(ptrPersonagem);
        else
            ptrPersonagem->setVelY(0),
            ptrPersonagem->setQtdPulos(0);
    }

    void GerenciadorColisoes::mostraHitbox(int x, int y, int width, int height) {
        RectangleShape shape(Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(Color::White);

        GerenciadorGrafico::getGerenciadorGrafico()->desenhaElemento(shape);
    }

    void GerenciadorColisoes::setJogador(Jogador *ptrJogador) {
        jogador = ptrJogador;
    }
}
