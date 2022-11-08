entidades := $(wildcard ./src/entidades/*.cpp) $(wildcard ./src/entidades/obstaculos/*.cpp) $(wildcard ./src/entidades/personagens/*.cpp) $(wildcard ./src/entidades/personagens/inimigos/*.cpp)
fases := $(wildcard ./src/fases/*.cpp)
gerenciadores := $(wildcard ./src/gerenciadores/*.cpp)
sources := main.cpp $(wildcard ./src/*.cpp) $(entidades) $(fases) $(gerenciadores)
outputs := $(wildcard ./obj/*.o)

compile: $(sources)
	g++ -I./SFML/include -c $(sources)
	move *.o ./obj

link: 
	g++ $(outputs) -o game -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-network -lsfml-audio -lsfml-system

game: compile link

clean:
	rm -f game
