CC=g++

HEADERS = $(wildcard *.h)

main: main.o 
	$(CC) main.o -o main  -lGL -lglut -lGLU -lm

%.o : %.cpp {HEADERS}
	g++  $<  -lGL -lglut -lGLU -lm -o $@

clean:
	rm -rf *.o