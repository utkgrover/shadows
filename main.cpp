#include "scene.h"

int angle=0;


void display(){
	displayFunction();
}

void init(){
	initialSettings();
}

void reshape(int width,int height){
	//winWidth=width;winHeight=height;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 1.0, 100.0); 
	glMatrixMode(GL_MODELVIEW);
}

void keypress(unsigned char key,int x,int y){
	if(key=='q') exit(0);
	//if(key=='s') spectacularfunc();
	//if(key=='d') diffusefunc();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Display Window");
	init();//placed skeptical funcs here
    glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keypress);
	glutMainLoop();
	return 0;
}