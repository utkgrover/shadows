#include<GL/glut.h>

//exit on keypress == q 
void keypress(unsigned char key, int x, int y) {
	if(key=='q')
		exit(0);

}

void reshape(int height,int width){

}

void display(){

}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Display Window");

    //declare init function 

    glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keypress);
	glutMainLoop();
	return 0;
}