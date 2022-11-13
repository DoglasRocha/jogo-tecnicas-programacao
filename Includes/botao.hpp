#include "./Entidades/entidade.hpp"
using entidades::Entidade;

class Botao:public Entidade
{
    private:
    const int tamX, tamY;
    Shape *shape;

    public:
        Botao(int posY);
        ~Botao();
        void executar();
        void processarEventos(Event evento);
        Drawable *getDraw();
        void desenhar();
        void setEmpuxo(int novoEmpuxo);
};