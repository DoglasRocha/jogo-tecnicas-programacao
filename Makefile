ifeq ($(OS), Windows_NT)
	MOVE=Move-Item
else
	MOVE=mv
endif

COMPILE := g++ -I./SFML/include -c

entidades := $(wildcard ./src/entidades/*.cpp) $(wildcard ./src/entidades/obstaculos/*.cpp) $(wildcard ./src/entidades/personagens/*.cpp) $(wildcard ./src/entidades/personagens/inimigos/*.cpp)
fases := $(wildcard ./src/fases/*.cpp)
gerenciadores := $(wildcard ./src/gerenciadores/*.cpp)
sources := main.cpp $(wildcard ./src/*.cpp)
outputs := $(wildcard ./obj/*.o)

game: compile link

cEntidades: $(entidadades)
	$(COMPILE) $(entidades)
	$(MOVE) *.o obj/

cFases: $(fases)
	$(COMPILE) $(fases)
	$(MOVE) *.o obj/

cGerenciadores: $(gerenciadores)
	$(COMPILE) $(gerenciadores)
	$(MOVE) *.o obj/

cSources: $(sources)
	$(COMPILE) $(sources)
	$(MOVE) *.o obj/

compile: cEntidades cFases cGerenciadores cSources

link: 
	g++ $(outputs) -o game -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-network -lsfml-audio -lsfml-system

clean:
	rm -f game
