#ifndef SCENE_H
#define SCENE_H
#include<GL/glut.h>
#include<iostream>

class Scene{
private:
    GLuint texture;
    const int textureWidth=512;
    const int textureHeight=512;

    GLfloat black[3]={0.0f,0.0f,0.0f};
    GLfloat dimwhite[3]={0.1f,0.1f,0.1f};
    GLfloat white[3]={1.0f,1.0f,1.0f};
    GLfloat shine=30.0f;
        
    GLfloat cameraProjection[16];
    GLfloat cameraView[16];
    GLfloat cameraPosition[3]={0.0f, 1.8f,-3.5f};

    GLfloat lightProjection[16];
    GLfloat lightView[16];
    GLfloat lightPosition[4]={2.0f, 2.6f,-3.0f,0.0f}; 

    GLfloat textureBias[16]={0.5f, 0.0f, 0.0f, 0.0f,0.0f, 0.5f, 0.0f, 0.0f,0.0f, 0.0f, 0.5f, 0.0f,0.5f, 0.5f, 0.5f, 1.0f};

    GLuint winWidth=500,winHeight=500;

public:
    void initialSettings();
    void displayFunction();
    void reshapeFunction(int ,int);
};

void drawscene();
//void initialSettings();
//void displayFunction();
void multiplyMatrix(GLfloat* a,GLfloat* b,GLfloat* ans[]);
void getRow(int rownum ,GLfloat* matrix,GLfloat* ans[]);


#endif