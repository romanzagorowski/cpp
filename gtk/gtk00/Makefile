all:
	gcc -Wall main.c `pkg-config gtk+-3.0 --cflags --libs`

pch:
	gcc -Wall pch.h `pkg-config gtk+-3.0 --cflags`

clean:
	rm -f a.* *.pch

