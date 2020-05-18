#include "scene.h"

/*! \brief processes keyboard input  
*   checks for keyboard input and takes action accordingly.
*   currently not set to store states but can by using a boolean array.
*/
void keypress(unsigned char key,int x,int y){
	//! exits/quits on press of key 'q' 
	if(key=='q') exit(0);
}


/*! \brief main function   
*	main function for the program .
*   contains standard glut initialization functions.
*   idle function is not used / glutredisplay() can be used instead if required. 
*/
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