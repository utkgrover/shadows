CC=g++

main: scene.cpp scene.h main.cpp
	$(CC) scene.cpp main.cpp -o main  -lGL -lglut -lGLU -lm

clean:
	rm -rf *.o