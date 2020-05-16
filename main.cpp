#include "scene.h"

void keypress(unsigned char key,int x,int y){
	if(key=='q') exit(0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Display Window");
	initialSettings();
    glutDisplayFunc(displayFunction);
	glutReshapeFunc(reshapeFunction);
	glutKeyboardFunc(keypress);
	glutMainLoop();
	return 0;
}