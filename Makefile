entidades := $(wildcard ./src/entidades/*.cpp) $(wildcard ./src/entidades/obstaculos/*.cpp) $(wildcard ./src/entidades/personagens/*.cpp)
fases := $(wildcard ./src/fases/*.cpp)
gerenciadores := $(wildcard ./src/gerenciadores/*.cpp)
sources := main.cpp $(wildcard ./src/*.cpp) $(entidades) $(fases) $(gerenciadores)                                                                                     

compile: $(sources)
	g++ -I./SFML/include -c $(sources)

link: 
	g++ main.o -o game -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-network -lsfml-audio -lsfml-system

main: $(sources)
	g++ -o game $(sources) -I./SFML/include -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-network -lsfml-audio -lsfml-system
	# export LD_LIBRARY_PATH=./SFML/lib ./game

game: compile link

clean:
	rm -f game
