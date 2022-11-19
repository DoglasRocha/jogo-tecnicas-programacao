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
    std::string path;
    sf::RectangleShape backgroundImage;
    sf::Texture *textura;

public:
    BackgroundManager(const std::string pathToImage="");
    ~BackgroundManager();
    void desenhar();
};

#endif //JOGO_TECNICAS_PROGRAMACAO_BACKGROUND_MANAGER_HPP
