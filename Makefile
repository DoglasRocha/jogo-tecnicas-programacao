main: 
	g++ -o main main.cpp -I./SFML/include -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=./SFML/lib
