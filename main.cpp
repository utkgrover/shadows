#include "scene.h"

int angle=0;


void display(){
	displayFunction();
}

void init(){
	initialSettings();
}

void reshape(int width,int height){
	reshapeFunction(width,height);
}

void keypress(unsigned char key,int x,int y){
	if(key=='q') exit(0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Display Window");
	init();//placed skeptical funcs here
    glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keypress);
	glutMainLoop();
	return 0;
}