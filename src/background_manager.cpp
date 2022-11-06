//
// Created by doglasrocha on 11/5/22.
//
#include "../Includes/background_manager.hpp"
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>

BackgroundManager::BackgroundManager(std::string pathToImage, GerenciadorGrafico *gG) {
    gerenGrafico = gG;

    std::stringstream buffer;
    buffer << "texturas/" << pathToImage;
    textura = new sf::Texture();

    if (!textura->loadFromFile(buffer.str())) {
        std::cout << "Não foi possível carregar o plano de fundo" << std::endl;
    }

    Vector2u tamJanela = gerenGrafico->getTamanhoJanela(),
        tamImagem = textura->getSize();

    float escalaX = (float) tamJanela.x / (float) tamImagem.x,
          escalaY = (float) tamJanela.y / (float) tamImagem.y;

    backgroundImage.setTexture(textura);
    backgroundImage.setSize(Vector2f(tamJanela.x, tamJanela.y));
}

BackgroundManager::~BackgroundManager() {
    delete textura;
}

void BackgroundManager::desenhar(GerenciadorGrafico *gG) {
    gG->desenhaElemento(backgroundImage);
}
