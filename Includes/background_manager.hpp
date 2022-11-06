//
// Created by doglasrocha on 11/5/22.
//

#ifndef JOGO_TECNICAS_PROGRAMACAO_BACKGROUND_MANAGER_HPP
#define JOGO_TECNICAS_PROGRAMACAO_BACKGROUND_MANAGER_HPP
#include "ente.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"
#include <string>
#include <SFML/Graphics.hpp>

using Gerenciadores::GerenciadorGrafico;

class BackgroundManager : public Ente {
private:
    GerenciadorGrafico *gerenGrafico;
    std::string path;
    sf::RectangleShape backgroundImage;
    sf::Texture *textura;

public:
    BackgroundManager(std::string pathToImage="", GerenciadorGrafico *gG=nullptr);
    ~BackgroundManager();
    void desenhar(GerenciadorGrafico *gG);
};

#endif //JOGO_TECNICAS_PROGRAMACAO_BACKGROUND_MANAGER_HPP
