#include "scene.h"

unsigned int texture;
const int textureWidth=512;
const int textureHeight=512;

GLfloat black[]={1.0f,1.0f,1.0f};
GLfloat dimwhite[]={0.1f,0.1f,0.1f};
GLfloat white[]={1.0f,1.0f,1.0f};
GLfloat shine=10.0f;

GLuint winWidth=500,winHeight=500;

GLfloat cameraProjection[16]={0.0f};
GLfloat cameraView[16]={0.0f};
GLfloat cameraPosition[]={1.0f,1.0f,1.0f};

GLfloat lightProjection[16]={0.0f};
GLfloat lightView[16]={0.0f};
GLfloat lightPosition[]={-2.0f,-2.0f,-2.0f}; 

GLfloat textureBias[]={0.5f, 0.0f, 0.0f, 0.0f,0.0f, 0.5f, 0.0f, 0.0f,0.0f, 0.0f, 0.5f, 0.0f,0.5f, 0.5f, 0.5f, 1.0f};

void drawscene(){
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
    //glRotatef(angle, 0.0f, 1.0f, 1.0f);
    glPushMatrix();
    glutSolidTorus(0.1, 0.3, 50, 50);
    glPopMatrix();

    // yellow torus
    //glRotatef(angle + 60, 1.0f, 0.0f, 0.0f);
    glColor3f(1.2f, 0.8f, 0.4f);
    glutSolidTorus(0.05, 0.13, 50, 50);

    glPopMatrix();
    glPopMatrix();
}

void initialSettings(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    
    // enables depth buffer 
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // enables face culling 
    glEnable(GL_CULL_FACE);

    // set normal vector to unit length 
    glEnable(GL_NORMALIZE);

    // set textures
    // reference - https://learnopengl.com/Getting-started/Textures
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);
    glTexImage2D(GL_TEXTURE_2D,0,GL_DEPTH_COMPONENT,textureWidth,textureHeight,0,GL_DEPTH_COMPONENT,GL_UNSIGNED_BYTE,NULL);
    //use gl_clamp to avoid repetition 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//try gl_nearest

    

	glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS , shine);

	// push matrix to stack 
	glPushMatrix();


    glLoadIdentity();
    gluPerspective(45.0f, (float)winWidth/winHeight, 1.0f, 100.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjection);

    glLoadIdentity();
	gluLookAt(cameraPosition[0], cameraPosition[1], cameraPosition[2],0.0f, 0.0f, 0.0f,0.0f, 1.0f, 0.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraView);

    glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 2.0f, 8.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, lightProjection);

	glLoadIdentity();
	gluLookAt(lightPosition[0],lightPosition[1],lightPosition[2],0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, lightView);

	glPopMatrix();

    std::cout<<"debug1"<<std::endl;
}

void displayFunction(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(lightProjection);

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(lightView);

    glViewport(0,0,textureWidth,textureHeight);
    glCullFace(GL_FRONT);
    glShadeModel(GL_FLAT);
    glColorMask(0, 0, 0, 0);

    //change the scene
    drawscene();

    glBindTexture(GL_TEXTURE_2D,texture);
    glCopyTexSubImage2D(GL_TEXTURE_2D,0,0,0,0,0,textureWidth,textureHeight);


    glCullFace(GL_BACK);
    glShadeModel(GL_SMOOTH);
    glColorMask(1,1,1,1);


    //second draw
    glClear(GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(cameraProjection);

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(cameraView);

	glViewport(0, 0, winWidth, winHeight);

	// Use dim light to represent shadowed areas
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT1, GL_AMBIENT,dimwhite);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, dimwhite);
	glLightfv(GL_LIGHT1, GL_SPECULAR, black);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

    drawscene();

    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);

    std::cout<<"debug3"<<std::endl;

    GLfloat* temp = multiplyMatrix(lightProjection,lightView);
    GLfloat* textureMatrix = multiplyMatrix(textureBias , temp);

    std::cout<<"debug4"<<std::endl;

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_S,GL_EYE_PLANE, getRow(0,textureMatrix));
	glEnable(GL_TEXTURE_GEN_S);

    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_T, GL_EYE_PLANE, getRow(1,textureMatrix));
	glEnable(GL_TEXTURE_GEN_T);

	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_R, GL_EYE_PLANE,getRow(2,textureMatrix) );
	glEnable(GL_TEXTURE_GEN_R);

	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_Q, GL_EYE_PLANE,getRow(3,textureMatrix) );
	glEnable(GL_TEXTURE_GEN_Q);

    glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE);

	// Shadow comparison should be true (ie not in shadow) if r<=texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL);

	// Shadow comparison should generate an INTENSITY result
	glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_INTENSITY);

    glAlphaFunc(GL_GEQUAL, 0.99f);
	glEnable(GL_ALPHA_TEST);

    drawscene();

    glDisable(GL_TEXTURE_2D);

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	glDisable(GL_TEXTURE_GEN_Q);
    glDisable(GL_LIGHTING);
	glDisable(GL_ALPHA_TEST);

    glFinish();
	glutSwapBuffers();
	glutPostRedisplay();
}

GLfloat* multiplyMatrix(GLfloat* a,GLfloat* b){
    GLfloat ans[16]={0.0f};
    ans[0]=a[0]*b[0]+a[1]*b[4]+a[2]*b[8]+a[3]*b[12];
    ans[1]=a[0]*b[1]+a[1]*b[5]+a[2]*b[9]+a[3]*b[13];
    ans[2]=a[0]*b[2]+a[1]*b[6]+a[2]*b[10]+a[3]*b[14];
    ans[3]=a[0]*b[3]+a[1]*b[7]+a[2]*b[11]+a[3]*b[15];

    ans[4]=a[4]*b[0]+a[5]*b[4]+a[6]*b[8]+a[7]*b[12];
    ans[5]=a[4]*b[1]+a[5]*b[5]+a[6]*b[9]+a[7]*b[13];
    ans[6]=a[4]*b[2]+a[5]*b[6]+a[6]*b[10]+a[7]*b[14];
    ans[7]=a[4]*b[3]+a[5]*b[7]+a[6]*b[11]+a[7]*b[15];

    ans[8]=a[8]*b[0]+a[9]*b[4]+a[10]*b[8]+a[11]*b[12];
    ans[9]=a[8]*b[1]+a[9]*b[5]+a[10]*b[9]+a[11]*b[13];
    ans[10]=a[8]*b[2]+a[9]*b[6]+a[10]*b[10]+a[11]*b[14];
    ans[11]=a[8]*b[3]+a[9]*b[7]+a[10]*b[11]+a[11]*b[15];

    ans[12]=a[12]*b[0]+a[13]*b[4]+a[14]*b[8]+a[15]*b[12];
    ans[13]=a[12]*b[1]+a[13]*b[5]+a[14]*b[9]+a[15]*b[13];
    ans[14]=a[12]*b[2]+a[13]*b[6]+a[14]*b[10]+a[15]*b[14];
    ans[15]=a[12]*b[3]+a[13]*b[7]+a[14]*b[11]+a[15]*b[15];

    return ans;
}

GLfloat* getRow(int rownum ,GLfloat* matrix){
    //already considering it to be a 4*4 matrix
    GLfloat ans[]={matrix[4*rownum],matrix[4*rownum+1],matrix[4*rownum+2],matrix[4*rownum+3]};
    return ans;
}