/* DO NOT EDIT THIS FILE - it is machine generated */
#include "com_example_opengl_c_es_MyGLView.h"
/* Header for class com_example_opengl_c_es_MyGLView */
#include <stdio.h>
#include<stdlib.h>
#include <android/log.h>
#include <math.h>
#include <stdlib.h>
#include <GLES/gl.h>
#include <GLES/glext.h>
#define LOG_TAG "System.out111"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

#define PI 3.14159265

float rotate=0;
int textureID;
int pause=0;

// Texture coordinates
static float textureCoords[] = {
0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f, 1.0f,1.0f,
0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f, 1.0f,1.0f,
0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f, 1.0f,1.0f,
0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f, 1.0f,1.0f,
0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f, 1.0f,1.0f,
0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f, 1.0f,1.0f
};
// Vertices
float vertices[] = {
	-1.0f,-1.0f, 1.0f, 1.0f,-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Front face
	1.0f,-1.0f, 1.0f, 1.0f,-1.0f,-1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,-1.0f, // Right face
	1.0f,-1.0f,-1.0f, -1.0f,-1.0f,-1.0f, 1.0f, 1.0f,-1.0f, -1.0f, 1.0f,-1.0f, // Back face
	-1.0f,-1.0f,-1.0f, -1.0f,-1.0f, 1.0f, -1.0f, 1.0f,-1.0f, -1.0f, 1.0f, 1.0f, // Left face
	-1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f, -1.0f,-1.0f, 1.0f, 1.0f,-1.0f, 1.0f, // Bottom face
	-1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1.0f, 1.0f,-1.0f, 1.0f, 1.0f,-1.0f // Top face
};
// Number of vertices
int count = 36;
// Normals
float normals[] = {
	0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Front face
	1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Right face
	0.0f, 0.0f,-1.0f, 0.0f, 0.0f,-1.0f, 0.0f, 0.0f,-1.0f, 0.0f, 0.0f,-1.0f, // Back face
	-1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, // Left face
	0.0f,-1.0f, 0.0f, 0.0f,-1.0f, 0.0f, 0.0f,-1.0f, 0.0f, 0.0f,-1.0f, 0.0f, // Bottom face
	0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f // Top face
};
// Indices
GLbyte indices[] = {
	0, 1, 3, 0, 3, 2,
	4, 5, 7, 4, 7, 6,
	8, 9, 11, 8, 11, 10,
	12, 13, 15, 12, 15, 14,
	16, 17, 19, 16, 19, 18,
	20, 21, 23, 20, 23, 22
};

static void gluPerspective(float fovy,float aspect,float zNear,float zFar){
	float ymax=zNear*(float)tan(fovy*PI/360);
	float ymin=-ymax;
	float xmin=ymin*aspect;
	float xmax=ymax*aspect;

	glFrustumf(xmin,xmax,ymin,ymax,zNear,zFar);
}
void JNICALL Java_com_example_opengl_1c_1es_MyGLView_nativeInit
  (JNIEnv *env, jclass clazz){
	LOGI("sdfsd");
	GLfloat gf=1.0f;
	//light buffers
	GLfloat lightAmbient[]={0.0f,0.0f,0.0f,1.0f};
	GLfloat lightDiffuse[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat lightPosition[]={2.0f,2.0f,10.0f,1.0f};

	//lights
	glLightfv(GL_LIGHT0,GL_AMBIENT,lightAmbient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightDiffuse);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//openGL settings
	glDisable(GL_DITHER);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColorx(0,0,0,1);
	glClearDepthf(1.0f);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	glEnableClientState(GL_VERTEX_ARRAY);

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glFrontFace(GL_CCW);
}

/*
 * Class:     com_example_opengl_c_es_MyGLView
 * Method:    nativeResize
 * Signature: (II)V
 */
void JNICALL Java_com_example_opengl_1c_1es_MyGLView_nativeResize
  (JNIEnv *env, jclass clazz, jint w, jint h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w / h, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*
 * Class:     com_example_opengl_c_es_MyGLView
 * Method:    nativeRender
 * Signature: ()V
 */
void JNICALL Java_com_example_opengl_1c_1es_MyGLView_nativeRender
  (JNIEnv *env, jclass clazz){
	// Clear screen
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		// Rotate if not paused
		if (!pause) rotate++;
		// Reset view matrix
		glLoadIdentity();
		// Bind texture
		glBindTexture(GL_TEXTURE_2D, textureID);
		// Point to the buffers
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
		glNormalPointer(GL_FLOAT, 0, normals);
		// Translate along the z axis
		glTranslatef(0.0f, 0.0f, -4.5f);
		// Rotate the cube
		glRotatef(rotate * 1.0f, 1,0,0);
		glRotatef(rotate * 0.7f, 0,1,0);
		glRotatef(rotate * 1.3f, 0,0,1);
		// Draw
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_BYTE, indices);

}

/*
 * Class:     com_example_opengl_c_es_MyGLView
 * Method:    nativeDone
 * Signature: ()V
 */
void JNICALL Java_com_example_opengl_1c_1es_MyGLView_nativePause
  (JNIEnv *env, jclass clazz){
	pause = !pause;
}
void JNICALL Java_com_example_opengl_1c_1es_MyGLView_nativePushTexture
  (JNIEnv *env, jclass clazz,jintArray arr,jint w,jint h){

	int len = w*h*4;
		char* body = (char*)env->GetIntArrayElements( arr, 0);
		char* data = (char*)malloc(len);
		// This converts the ARGB data from Java into RGBA data OpenGL can use.
		int i;
		for (i = 0; i < len; i += 4) {
		data[i] = body[i+2];
		data[i+1] = body[i+1];
		data[i+2] = body[i];
		data[i+3] = body[i+3];
		}
		glGenTextures(1, (GLuint*)&textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, (void*)data);
}
