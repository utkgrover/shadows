#include "scene.h"

//! to map the texute
GLuint texture;
//! texture width
const int textureWidth=512;
//! texture height 
const int textureHeight=512;

//! defined the colour black 
GLfloat black[]={0.0f,0.0f,0.0f};
//! defined a dim shade of white 
GLfloat dimwhite[]={0.1f,0.1f,0.1f};
//! defined white colour 
GLfloat white[]={1.0f,1.0f,1.0f};
//! defined shine component for materials
GLfloat shine=30.0f;

//! defined window width,height 
GLuint winWidth=500,winHeight=500;

//! camera projection matrix
GLfloat cameraProjection[16];
//! camera view matrix
GLfloat cameraView[16];
//! camera position vector 
GLfloat cameraPosition[]={0.0f, 1.8f,-3.5f};

//! light projection matrix
GLfloat lightProjection[16];
//! ligth view matrix
GLfloat lightView[16];
//! light position vector 
GLfloat lightPosition[]={2.0f, 2.6f,-3.0f,0.0f}; 

//! texture bias to get the shadow 
GLfloat textureBias[]={0.5f, 0.0f, 0.0f, 0.0f,0.0f, 0.5f, 0.0f, 0.0f,0.0f, 0.0f, 0.5f, 0.0f,0.5f, 0.5f, 0.5f, 1.0f};

//! draws the scene 
void drawscene(){
    int angle=4;

    glPushMatrix();
    glColor3f(0.4f, 0.3f, 0.3f);
    glTranslatef(0.0f, 0.0f, 1.0f);
    glScalef(1.0f, 0.05f, 1.0f);
    glutSolidCube(6.0f);
    glPopMatrix();
    glPushMatrix();

    glPushMatrix();
    glColor3f(0.1f, 0.9f, 0.0f);
    glTranslatef(0.0f, 0.5f, 0.0f);
    //glScalef(1.0f, 0.05f, 1.0f);
    glutSolidTeapot(0.3f);
    glPopMatrix();
    //glPushMatrix();
    

    // glColor3f(1.0f, 0.3f, 0.3f);
    // glTranslatef(0.0f, 1.0f, 0.0f);
    // glRotatef(angle, 0.0f, 1.0f, 1.0f);
    // glPushMatrix();
    // glutSolidTorus(0.1, 0.3, 50, 50);
    // glPopMatrix();

    // glRotatef(angle + 60, 1.0f, 0.0f, 0.0f);
    // glColor3f(1.2f, 0.8f, 0.4f);
    // glutSolidCube(0.2f);

    // glPopMatrix();
    // glPopMatrix();
}

//! initial settings 
void initialSettings(){
    //! sets matrix to modelview
    glMatrixMode(GL_MODELVIEW);

    //! loads the identity matrix,clearing out garbage values 
    glLoadIdentity();

    //! enable smooth shading 
    glShadeModel(GL_SMOOTH);
    //! set clear colour 
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    //! set object colour 
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    
    //! clear depth buffer 
    glClearDepth(1.0f);
    //! enable depth buffer 
    glEnable(GL_DEPTH_TEST);
    //! specify depth function 
    glDepthFunc(GL_LEQUAL);

    //! enable face culling 
    glEnable(GL_CULL_FACE);

    //!enable normalization-set normal vector to unit length 
    glEnable(GL_NORMALIZE);

    //! set textures-reference - https://learnopengl.com/Getting-started/Textures
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);
    glTexImage2D(GL_TEXTURE_2D,0,GL_DEPTH_COMPONENT,textureWidth,textureHeight,0,GL_DEPTH_COMPONENT,GL_UNSIGNED_BYTE,NULL);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//try gl_nearest
    
    //! enable material colouring 
	glEnable(GL_COLOR_MATERIAL);
    //! specify material colouring 
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    //! set material colour attribute
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //! set material colour attribute
	glMaterialf(GL_FRONT, GL_SHININESS , shine);

	//! push matrix to stack 
	glPushMatrix();
    //! clear previous values 
    glLoadIdentity();

    gluPerspective(45.0f, (float)winWidth/winHeight, 1.0f, 100.0f);
    //! get cameraprojection matrix
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjection);

    glLoadIdentity();
	gluLookAt(cameraPosition[0], cameraPosition[1], cameraPosition[2],0.0f, 0.0f, 0.0f,0.0f, 1.0f, 0.0f);
	//! get camera view matrix
    glGetFloatv(GL_MODELVIEW_MATRIX, cameraView);

    glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 2.0f, 8.0f);
    //! get light projection matrix 
	glGetFloatv(GL_MODELVIEW_MATRIX, lightProjection);

	glLoadIdentity();
	gluLookAt(lightPosition[0],lightPosition[1],lightPosition[2],0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
    //! get light view matrix 
    glGetFloatv(GL_MODELVIEW_MATRIX, lightView);

	glPopMatrix();    
}

void displayFunction(){
    //! clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //! set matrix to projection mode
    glMatrixMode(GL_PROJECTION);
    //! load light projection matrix
	glLoadMatrixf(lightProjection);

    //! set martix to model view
	glMatrixMode(GL_MODELVIEW);
    //! load lightviewmatrix
	glLoadMatrixf(lightView);

    //! set viewport
    glViewport(0,0,textureWidth,textureHeight);
    glCullFace(GL_FRONT);
    glShadeModel(GL_FLAT);
    glColorMask(0, 0, 0, 0);

    //! draw scene
    drawscene();
    //! bind the texture geerated 
    glBindTexture(GL_TEXTURE_2D,texture);
    glCopyTexSubImage2D(GL_TEXTURE_2D,0,0,0,0,0,textureWidth,textureHeight);

    //! restore initial states
    glCullFace(GL_BACK);
    glShadeModel(GL_SMOOTH);
    glColorMask(1,1,1,1);

    //! clear depth buffer
    glClear(GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(cameraProjection);

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(cameraView);

	glViewport(0, 0, winWidth, winHeight);

    //! enable lighting 
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT,dimwhite);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dimwhite);
	glLightfv(GL_LIGHT0, GL_SPECULAR, black);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

    //! drawscene
    drawscene();
    
    //! lighting settings 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    //! getting shadow texture
    GLfloat *temp,*textureMatrix,*row;
    multiplyMatrix(lightProjection , textureBias , &temp);
    multiplyMatrix(lightView , temp , &textureMatrix);

    //! applying texture
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    getColumn(0,textureMatrix,&row);
	glTexGenfv(GL_S,GL_EYE_PLANE, row);
	glEnable(GL_TEXTURE_GEN_S);
    //! applying texture
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    getColumn(1,textureMatrix,&row);
	glTexGenfv(GL_T, GL_EYE_PLANE,row);
	glEnable(GL_TEXTURE_GEN_T);
    //! applying texture
	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    getColumn(2,textureMatrix,&row);
	glTexGenfv(GL_R, GL_EYE_PLANE,row );
	glEnable(GL_TEXTURE_GEN_R);
    //! applying texture
	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    getColumn(3,textureMatrix,&row);
	glTexGenfv(GL_Q, GL_EYE_PLANE,row);
	glEnable(GL_TEXTURE_GEN_Q);
    //! applying texture
    glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE);

	//! Shadow comparison should be true (ie not in shadow) if r<=texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL);

	//! Shadow comparison should generate an INTENSITY result
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
	//glutPostRedisplay();
}

void multiplyMatrix(GLfloat* a,GLfloat* b,GLfloat* ans[]){
    *ans = new GLfloat[16];
    (*ans)[0]=a[0]*b[0]+a[1]*b[4]+a[2]*b[8]+a[3]*b[12];
    (*ans)[1]=a[0]*b[1]+a[1]*b[5]+a[2]*b[9]+a[3]*b[13];
    (*ans)[2]=a[0]*b[2]+a[1]*b[6]+a[2]*b[10]+a[3]*b[14];
    (*ans)[3]=a[0]*b[3]+a[1]*b[7]+a[2]*b[11]+a[3]*b[15];

    (*ans)[4]=a[4]*b[0]+a[5]*b[4]+a[6]*b[8]+a[7]*b[12];
    (*ans)[5]=a[4]*b[1]+a[5]*b[5]+a[6]*b[9]+a[7]*b[13];
    (*ans)[6]=a[4]*b[2]+a[5]*b[6]+a[6]*b[10]+a[7]*b[14];
    (*ans)[7]=a[4]*b[3]+a[5]*b[7]+a[6]*b[11]+a[7]*b[15];

    (*ans)[8]=a[8]*b[0]+a[9]*b[4]+a[10]*b[8]+a[11]*b[12];
    (*ans)[9]=a[8]*b[1]+a[9]*b[5]+a[10]*b[9]+a[11]*b[13];
    (*ans)[10]=a[8]*b[2]+a[9]*b[6]+a[10]*b[10]+a[11]*b[14];
    (*ans)[11]=a[8]*b[3]+a[9]*b[7]+a[10]*b[11]+a[11]*b[15];

    (*ans)[12]=a[12]*b[0]+a[13]*b[4]+a[14]*b[8]+a[15]*b[12];
    (*ans)[13]=a[12]*b[1]+a[13]*b[5]+a[14]*b[9]+a[15]*b[13];
    (*ans)[14]=a[12]*b[2]+a[13]*b[6]+a[14]*b[10]+a[15]*b[14];
    (*ans)[15]=a[12]*b[3]+a[13]*b[7]+a[14]*b[11]+a[15]*b[15];

}

void getColumn(int rownum ,GLfloat* matrix,GLfloat* ans[]){
    *ans = new GLfloat[4];

    for(int i=0;i<4;i++) (*ans)[i] = matrix[4*i+rownum];
}

void reshapeFunction(int w, int h) {
	winWidth = w, winHeight = h;
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(45.0f, (float)winWidth/winHeight, 1.0f, 100.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjection );
	glPopMatrix();
}