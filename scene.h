#ifndef SCENE_H
#define SCENE_H

#include<GL/glut.h>

void getsettings(){
    glEnable(GL_COLOR_MATERIAL);//to keep the material same as the colour when lightening is enabled 
	//check if blending is really needed
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}

void drawscene(int angle){
    //draw cube
    glTranslatef(0.0f,0.0f,-5.0f);
    glRotatef(angle,1.0f,1.0f,0.0f);
    glScalef(1.0f,0.3f,1.0f);
    // glColor4f(0.3f,0.3f,0.3f,1.0f);
	// glutSolidCube(2.0f);

    //change this 
    // glColor4f(0.0f,1.0f,0.0f,1.0f);
    // glutSolidTorus(0.05, 0.13, 50, 50);

    glColor4f(1.0f,0.0f,0.0f,0.5f);
    glutSolidCube(2.0f);
}

#endif