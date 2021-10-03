#pragma once
#include <iostream>
#include "../glew-2.1.0/include/GL/glew.h" 
#include "../freeglut/include/GL/freeglut.h"
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <windows.h>

#define SIZE 20
#define SQL_RESULT_LEN 1024
#define SQL_RETURN_CODE_LEN 1024
using namespace std;

//
//	/* This is the settings for gl coordinate */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	/* void glOrtho(double left, double  right, double  bottom, double  top, double  nearVal, double  farVal); */
//	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
//}


void Init()
{
	glClearColor(0,0,0,0);
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

void drawText(const char* text, int len, int x, int y) {
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
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Print a character on the screen
	}
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

	std::string text;
	text = "LIBRARY MANAGEMENT";
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

void ScreenWindow()
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Manager Library");
}



