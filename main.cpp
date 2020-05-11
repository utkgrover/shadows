#include "scene.h"

int angle=0;

void display(){
	angle+=2;
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); //Loads identity matrix to reset drawing location 

	drawscene(angle);

	glutSwapBuffers();
	glutPostRedisplay();
}

void reshape(int width,int height){
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 1.0, 100.0); 
	glMatrixMode(GL_MODELVIEW);
}

void keypress(unsigned char key,int x,int y){
	if(key=='q') exit(0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Display Window");
	getsettings();//placed skeptical funcs here
    glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keypress);
	glutMainLoop();
	return 0;
}