#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Gerenciadores
{
	class GerenciadorGrafico 
	{
	private:
		RenderWindow *window;
		View *view;
		static GerenciadorGrafico *instance;

	protected:
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico *getInstance();
		static void deleteInstance();
		RenderWindow *getWindow();
        const bool verificaJanelaAberta();
        void limpaJanela();
        void desenhaElemento(Drawable &drawable);
        void mostraElementos();
        void fechaJanela();
        Vector2u getTamanhoJanela();
		void centralizarJanela(int x);
		Vector2f getCentroView();
	};
}
