#include "../../Includes/Gerenciadores/gerenciador_colisoes.hpp"
#include "../../Includes/Gerenciadores/gerenciador_grafico.hpp"
#include <iostream>
#include <list>

using namespace sf;
using namespace std;

namespace Gerenciadores
{

    GerenciadorColisoes::GerenciadorColisoes():gravidade(1) {
        ptrProjetil = nullptr;
        jogador2 = nullptr;
    }

    GerenciadorColisoes *GerenciadorColisoes::getInstance() {
        if (instance == nullptr)
            instance = new GerenciadorColisoes();

        return instance;
    }

    void GerenciadorColisoes::deleteInstance() {
        if (instance) {
            delete instance;
            instance = nullptr;
        }
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
        
    }

    void GerenciadorColisoes::aplicaGravidade(Personagem *personagem)
    {
        personagem->setVelY(personagem->getVelY() + gravidade + personagem->getEmpuxo());
        personagem->setEmpuxo(personagem->getEmpuxo() + gravidade);
    }

    void GerenciadorColisoes::executar() {
        for (int i = 0, l = vetorInimigos.size(); i < l; i++) {
            moveX = moveY = true;

            if (!vetorInimigos[i]->getVivo()) continue;

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
        if(ptrProjetil) executaColisaoProjetilComEntidade();
    }

    void GerenciadorColisoes::executarColisoesJogador() {
        moveX = moveY = true;
        executaColisaoJogadorComInimigo();
        executaColisoesObstaculos(jogador);
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
                    if(!(*it)->getAtravessar()) moveX = false;
                    else 
                    {
                        (*it)->interage(ptrPersonagem);
                        ptrPersonagem->checaVivo();
                    }
                    
                }

                bPersFuturo = bPersAtual;
                bPersFuturo.top += deltaY;
                if (boundsObstaculo.intersects(bPersFuturo)){
                    if(!(*it)->getAtravessar()) moveY = false;
                }
            }
        }

        bPersFuturo.left += deltaX;
        mostraHitbox(bPersFuturo.left, bPersFuturo.top, bPersFuturo.width, bPersFuturo.height);
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

    void GerenciadorColisoes::setJogador2(Jogador *ptrJogador) {
        jogador2 = ptrJogador;
    }

    void GerenciadorColisoes::setProjetil(Projetil *ptrProjetil_){
        ptrProjetil = ptrProjetil_; 
    }

    vector<Inimigo*> GerenciadorColisoes::getVetorInimigos(){
        return vetorInimigos;
    }

    void GerenciadorColisoes::executaColisaoJogadorComInimigo() {

        FloatRect bJogador = jogador->getSprite()->getGlobalBounds(),
            bJogadorFuturo = bJogador;
        int deltaX = jogador->getVelX(),
            deltaY = jogador->getVelY() + jogador->getEmpuxo();
        vector<Inimigo*>::iterator it;

        bJogadorFuturo.top += deltaY, bJogadorFuturo.left += deltaX;

        for (int i = 0, l = vetorInimigos.size(); i < l; i++) {
            if (!vetorInimigos[i]->getVivo()) 
            {
                jogador->ganhaPontuacao(vetorInimigos[i]->getPontos());
                it = vetorInimigos.begin() + i;
                vetorInimigos.erase(it);
            }

            FloatRect boundsInimigo = vetorInimigos[i]->getSprite()->getGlobalBounds();

            if (boundsInimigo.intersects(bJogadorFuturo)) {
                bJogadorFuturo = bJogador;
                bJogadorFuturo.left += deltaX;
                if (boundsInimigo.intersects(bJogadorFuturo)) {
                    if (bJogadorFuturo.left < boundsInimigo.left)
                        jogador->repelirX(-1);
                    else
                        jogador->repelirX(1);
                    
                    jogador->recebeAtaque(vetorInimigos[i]);
                }
                
                bJogadorFuturo = bJogador;
                bJogadorFuturo.top += deltaY;
                if (boundsInimigo.intersects(bJogadorFuturo) &&
                    bJogador.top + bJogador.height < boundsInimigo.top)
                    jogador->repelirY(), 
                    moveY = false,
                    vetorInimigos[i]->recebeAtaque(jogador);
            }
        }

        bJogadorFuturo.left += deltaX;
        mostraHitbox(bJogadorFuturo.left, bJogadorFuturo.top, bJogadorFuturo.width, bJogadorFuturo.height);
    }

    void GerenciadorColisoes::executaColisaoProjetilComEntidade(){
        ptrProjetil->setVelY(gravidade * 2);
        FloatRect bProjetil = ptrProjetil->getSprite()->getGlobalBounds();
        int deltaX = ptrProjetil->getVelX(),
            deltaY = ptrProjetil->getVelY() + ptrProjetil->getEmpuxo();
        
         FloatRect boundsJogador = jogador->getSprite()->getGlobalBounds();

         if (bProjetil.intersects(boundsJogador)) {
                if (boundsJogador.left < bProjetil.left)
                        jogador->repelirX(-1);
                else
                        jogador->repelirX(1);
                ptrProjetil->reset();
                    
                jogador->recebeAtaque(ptrProjetil->getAtaque());
        }
        else{
            ptrProjetil->moverX();
            ptrProjetil->moverY();
        }

        std::list<Obstaculo *>::iterator it;
        for (it = listaObstaculos.begin(); it != listaObstaculos.end(); it++) {
            FloatRect boundsObstaculo = (*it)->getShape()->getGlobalBounds();
            if (boundsObstaculo.intersects(bProjetil)) ptrProjetil->reset();           
        }
    }
                

    void GerenciadorColisoes::limparListas() {
        vetorInimigos.clear();
        listaObstaculos.clear();
    }
}
