#pragma once
#include <iostream>
#include "../glew-2.1.0/include/GL/glew.h" 
#include "../freeglut/include/GL/freeglut.h"

#define SIZE 20
#define SIZE_WIDTH_WINDOW 1100
#define SIZE_HEIGHT_WINDOW 650
#define TITLE_WINDOW "Library Management"

using namespace std;

#pragma region _OPENGL_INIT_

void initWindownOpenGL(int argc, char** argv);
void Init();

#pragma endregion



#pragma region _OPENGL_EVENT_
void MouseButton(int type, int state, int x, int y);

#pragma endregion



#pragma region _OPENGL_FUNCTION
void ReShape(int width, int height);
void drawText(const char* text, int len, int x, int y);
void RenderScene();

#pragma endregion


void initWindownOpenGL(int argc, char** argv)
{
	glutInit(&argc, argv); // khoi tao glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // thiet lap che do mau
	glutInitWindowSize(SIZE_WIDTH_WINDOW, SIZE_HEIGHT_WINDOW);// thiet lap kich thuoc cua so
	glutInitWindowPosition(100, 100);// vi tri cua so tai toa do 0 0 cua man hinh
	glutCreateWindow(TITLE_WINDOW);
	glutReshapeFunc(ReShape);
	Init();
}

void Init()
{
	glClearColor(0, 0, 0, 0);
	glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
}

void ReShape(int width, int height) // xu li su kien khi kich thuoc thay doi
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// toa do ve 
   //glMatrixMode(GL_MODELVIEW);
}

void drawText(const char* text, int len, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double* matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1., 0., 0.);
	glRasterPos2i(x, y);
	for (int i = 0; i < len; i++)  // loop until i is greater then l
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Print a character on the screen
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT); // xoa mau trong buffer 

	glColor3f(242.0f, 233.0f, 228.0f);
	glViewport(50, 50, 600, 600);// khung nhin 

	glBegin(GL_POLYGON); // ve hinh vuong: gl polygon
	glVertex2f(-SIZE, -SIZE);
	glVertex2f(-SIZE, SIZE);
	glVertex2f(SIZE, SIZE);
	glVertex2f(SIZE, -SIZE);
	glEnd();

	std::string text = "LIBRARY MANAGEMENT";
	drawText(text.data(), text.size(), 0, 0);

	glFlush(); // sinh anh dua ra vung dem khung
}

void MouseButton(int type, int state, int x, int y) {
	if (type == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glColor3f(0, 232, 228.0f);
			glBegin(GL_POLYGON); // ve hinh vuong: gl polygon
			glVertex2f(-SIZE, -SIZE);
			glVertex2f(-SIZE, SIZE);
			glVertex2f(SIZE, SIZE);
			glVertex2f(SIZE, -SIZE);
			glEnd();

			glFlush();
		}
		else {
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glColor3f(0, 232, 228.0f);
			glBegin(GL_POLYGON); // ve hinh vuong: gl polygon
			glVertex2f(-SIZE, -SIZE);
			glVertex2f(-SIZE, SIZE);
			glVertex2f(SIZE, SIZE);
			glVertex2f(SIZE, -SIZE);
			glEnd();
			glFlush();
		}
	}
}


