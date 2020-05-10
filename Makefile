CC=g++

HEADERS = $(wildcard *.h)

main: main.o scene.h
	$(CC) main.o -o main  -lGL -lglut -lGLU -lm

%.o : %.cpp {HEADERS}
	g++  $<  -lGL -lglut -lGLU -lm -o $@

clean:
	rm -rf *.o