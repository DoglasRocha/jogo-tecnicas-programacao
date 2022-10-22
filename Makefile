entidades := $(wildcard ./src/entidades/*.cpp) $(wildcard ./src/entidades/obstaculos/*.cpp) $(wildcard ./src/entidades/personagens/*.cpp)
fases := $(wildcard ./src/fases/*.cpp)
gerenciadores := $(wildcard ./src/gerenciadores/*.cpp)
sources := main.cpp $(wildcard ./src/*.cpp) $(entidades) $(fases) $(gerenciadores)                                                                                     

main: $(all)
	g++ -o game $(sources) -I./SFML/include -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-network -lsfml-audio -lsfml-system
	# export LD_LIBRARY_PATH=./SFML/lib ./game

clean:
	rm -f game