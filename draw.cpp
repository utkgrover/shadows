#include "draw.h"

void Draw::display1(){
    int angle=4;

    glPushMatrix();
    glColor3f(0.4f, 0.3f, 0.3f);
    glTranslatef(0.0f, 0.0f, 1.0f);
    glScalef(0.95f, 0.05f, 0.95f);
    glutSolidCube(5.0f);
    glPopMatrix();
    glPushMatrix();

    // red torus
    glColor3f(1.0f, 0.3f, 0.3f);
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotatef(angle, 0.0f, 1.0f, 1.0f);
    glPushMatrix();
    glutSolidTorus(0.1, 0.3, 50, 50);
    glPopMatrix();

    // yellow torus
    glRotatef(angle + 60, 1.0f, 0.0f, 0.0f);
    glColor3f(1.2f, 0.8f, 0.4f);
    glutSolidCube(0.2f);

    glPopMatrix();
    glPopMatrix();
}


void Draw::display2(){
    glColor3f(0.0f, 0.0f, 1.0f);
    glPushMatrix();

    glScalef(1.0f, 0.05f, 1.0f);
    glutSolidCube(3.0f);

    glPopMatrix();

    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();

    glTranslatef(0.0f, 0.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glutSolidTorus(0.2, 0.5, 24, 48);

    glPopMatrix();
}