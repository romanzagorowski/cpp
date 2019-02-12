all:
	g++ -Wall -std=c++11 main.cpp mywindow.cpp mydrawingarea.cpp `pkg-config --libs --cflags gtkmm-3.0`

pch:
	g++ -c -Wall -std=c++11 pch.h `pkg-config --cflags gtkmm-3.0`

clean:
	rm -f a.* *.gch

