CC=g++
CCFLAGS= -Wall -g

main: main.o scene.o draw.o
	$(CC) $(CCFLAGS) -o main main.o scene.o draw.o -lGL -lglut -lGLU -lm

main.o: main.cpp scene.h
	$(CC) $(CCFLAGS) -c main.cpp 

scene.o: scene.h draw.h
	$(CC) $(CCFLAGS) -c scene.cpp 

draw.o: draw.h
	$(CC) $(CCFLAGS) -c draw.cpp 
	
clean:
	rm -rf *.o main