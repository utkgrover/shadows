#include "scene.h"

Scene s;

void display(){
	s.displayFunction();
}

void keypress(unsigned char key,int x,int y){
	if(key=='q') exit(0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Display Window");

	s.initialSettings();
    glutDisplayFunc(display);
	glutReshapeFunc(reshapeFunction);
	glutKeyboardFunc(keypress);
	glutMainLoop();
	return 0;
}