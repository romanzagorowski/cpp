all:
	g++ -Wall -std=c++11 main.cpp `pkg-config --libs --cflags gtkmm-3.0`

pch:
	g++ -std=c++11 pch.h `pkg-config --cflags gtkmm-3.0`

clean:
	rm -f a.* *.gch

