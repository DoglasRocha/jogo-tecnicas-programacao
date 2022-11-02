#cmake_minimum_required(VERSION 3.23)
#project(jogo_tecnicas_programacao)
#
#set(CMAKE_CXX_STANDARD 14)
##include_directories(${PROJECT_SOURCE_DIR}/SFML/include)
##link_directories("${PROJECT_SOURCE_DIR}/SFML/lib")
#
#file(GLOB ENTIDADES "${PROJECT_SOURCE_DIR}/src/entidades/*.cpp" "./src/entidades/obstaculos/*.cpp" "./src/entidades/personagens/*.cpp" "./src/entidades/personagens/inimigos/*.cpp")
#file(GLOB FASES "./src/fases/*.cpp")
#file(GLOB GERENCIADORES "./src/gerenciadores/*.cpp")
#file(GLOB SOURCES main.cpp ${ENTIDADES} ${FASES} ${GERENCIADORES})
#add_executable(jogo_tecnicas_programacao ${SOURCES} Includes/Entidades/Obstaculos/plataforma.hpp src/entidades/obstaculos/plataforma.cpp)
#include_directories(${PROJECT_SOURCE_DIR}/SFML/include)
#
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
##find_package(SFML REQUIRED system window graphics network audio)
##if(SFML_FOUND)
##    include_directories(${SFML_INCLUDE_DIR})
##    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
##endif()
#
#target_link_libraries(jogo_tecnicas_programacao sfml-graphics sfml-window sfml-system sfml-graphics sfml-audio)