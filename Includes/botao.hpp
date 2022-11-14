#include "./Entidades/entidade.hpp"
#include <string>
using entidades::Entidade;
using namespace std;
using namespace sf;

class Botao : public Entidade
{
    private:
        const int tamX, tamY;
        Shape *shape;
        Texture *textura;

    public:
        Botao();
        Botao(int posY, string texturastring);
        ~Botao();
        void executar(); // //
        void processarEventos(Event evento); //
        Drawable *getDraw(); //
        Shape *getShape();
        void desenhar(); // //
        void setEmpuxo(int novoEmpuxo); //
};