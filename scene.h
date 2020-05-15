#ifndef SCENE_H
#define SCENE_H
#include<GL/glut.h>
#include<iostream>
// bool diffuse=false,emmisive=false,spectacular=false;

// GLfloat redDiffuseMaterial[]={1.0,0.0,0.0};
// GLfloat whiteSpectacularMaterial[]={1.0,1.0,1.0};
// GLfloat greenEmissiveMaterial[]={0.0,1.0,0.0};
// GLfloat lightPosition[] =   {1.0f,1.0f,1.0f,0.0f};
// GLfloat specularLight[] =   {1.0, 1.0, 1.0};  //set specular light 
// GLfloat ambientLight[]  =   {0.0, 0.0, 0.0};   //set ambient light 
// GLfloat diffuseLight[]  =   {1.0, 1.0, 1.0};   //set diffuse light
// GLfloat blankMaterial[] =   {0.0,0.0,0.0};      //set blank material 
// GLfloat mShininess[]    =   {10};                  //set shininess

// void spectacularfunc(){
//     if(spectacular){
//         spectacular=false;
//         glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blankMaterial);
//         glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, blankMaterial);
//     }else{
//         spectacular=true;
//         glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whiteSpectacularMaterial);
//         glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
//     }
// }

// //idk what this shiz is 
// void diffusefunc(){
//     if(diffuse){
//         diffuse=false;
//         glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blankMaterial);
//     }else{
//         diffuse=true;
//         glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, redDiffuseMaterial);
//     }
// }


// void getsettings(){
//     //to keep the material same as the colour when lightening is enabled
//     glEnable(GL_COLOR_MATERIAL); 

// 	//check if blending is really needed
// 	glEnable(GL_BLEND);
// 	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

//     //enable depth 
//     glClearDepth(1.0f);
//     glEnable(GL_DEPTH_TEST);

//     //enable lighting 
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT0);

//     //adding colours to light 
//     glLightfv(GL_LIGHT0,GL_SPECULAR,specularLight);
//     glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
//     glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
//     glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

//     //enable smooth shading
//     glShadeModel(GL_SMOOTH);
// }

void drawscene();
void initialSettings();
void displayFunction();
GLfloat* multiplyMatrix(GLfloat*,GLfloat*);
GLfloat* getRow(int,GLfloat*);

#endif