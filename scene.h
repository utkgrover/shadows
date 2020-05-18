#ifndef SCENE_H
#define SCENE_H
#include<GL/glut.h>

/*! \brief draws the scene 
*   all the components that have been drawn into the scene have been put here .
*   Can add / remove anything without any hustle
*/
void drawscene();


//! display settings only to be called once 

//! display settings that only need to be called once or any form id declarion is kept here
//! stuff can be added or removed if needed , eg - smooth shading can be changed to flat for faster refresh rate
void initialSettings();


//! main display function 

//! fucntion where all calculations / plotting takes place . 
//! The scene is plotted thrice with different settings to achieve the effect
void displayFunction();


//! to multiply 4x4 matrix

//! function to multiply 4x4 matrix which is needed in display function 
void multiplyMatrix(GLfloat* a,GLfloat* b,GLfloat* ans[]);


//! returns column from 4x4 matrix
void getColumn(int rownum ,GLfloat* matrix,GLfloat* ans[]);

//! replots the scene on window reshape 
void reshapeFunction(int ,int );

#endif