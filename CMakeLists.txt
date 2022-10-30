cmake_minimum_required(VERSION 3.23)
project(jogo_tecnicas_programacao)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/SFML/include)

add_executable(jogo_tecnicas_programacao
        main.cpp Includes/listas/lista_circular.hpp)
