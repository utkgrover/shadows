#ifndef SCENE_H
#define SCENE_H
#include<GL/glut.h>
#include<iostream>

void drawscene();
void initialSettings();
void displayFunction();
void multiplyMatrix(GLfloat* a,GLfloat* b,GLfloat* ans[]);
void getRow(int rownum ,GLfloat* matrix,GLfloat* ans[]);
void reshapeFunction(int ,int );

#endif