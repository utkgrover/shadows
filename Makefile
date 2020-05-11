CC=g++

main: scene.h main.cpp
	$(CC) main.cpp -o main  -lGL -lglut -lGLU -lm

clean:
	rm -rf *.o