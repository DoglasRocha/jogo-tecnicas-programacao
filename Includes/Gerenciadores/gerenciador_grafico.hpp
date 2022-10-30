#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Gerenciadores
{
	class GerenciadorGrafico 
	{
	private:
		RenderWindow window;
		static GerenciadorGrafico *instance;

	protected:
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico *getInstance();
		RenderWindow *getWindow();
	};
}
