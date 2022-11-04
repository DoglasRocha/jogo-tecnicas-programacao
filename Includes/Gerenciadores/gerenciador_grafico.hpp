#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Gerenciadores
{
	class GerenciadorGrafico 
	{
	private:
		RenderWindow *window;
		static GerenciadorGrafico *instance;

	protected:
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico *getGerenciadorGrafico();
		RenderWindow *getWindow();
        const bool verificaJanelaAberta();
        void limpaJanela();
        void desenhaElemento(Drawable &drawable);
        void mostraElementos();
        void fechaJanela();
	};
}
