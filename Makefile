CC=g++

main: draw.h draw.cpp scene.cpp scene.h main.cpp
	$(CC) draw.cpp scene.cpp main.cpp -o main  -lGL -lglut -lGLU -lm

clean:
	rm -rf *.o