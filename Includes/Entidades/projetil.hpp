#pragma once
#include "entidade.hpp"
#include "Personagens/Inimigos/minotauro.hpp"
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace entidades::personagens;

namespace entidades
{
	class Projetil : public Entidade
	{
	private:
		int velX, velY, ataque;
		std::string sentido;
		Sprite *sprite;
		Texture *textura;
		Minotauro *ptrMino;

	public:
		Projetil(Minotauro* ptrMino_);
		~Projetil();
		void desenhar();
		void moverX();
        void moverY();
		void colideX();
		void colideY();
		void reset();
        void setVelX(const int novaVel);
        void setVelY(const int novaVel);
        int getVelX() const;
        int getVelY() const;
		Drawable *getDraw();
        Sprite* getSprite();
        void processarEventos(Event evento);
		int getAtaque();
		void setEmpuxo(int novoEmpuxo);
	};
}
