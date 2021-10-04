#include <iostream>
#include "Header/functionSQL.h"
#include "Header/libraryFun.h"
#include "Header/openGL.h"

using namespace std;

int main(int argc, char** argv) {

	initWindownOpenGL(argc, argv);

	glutDisplayFunc(RenderScene);// khi cua so man hinh hien thi

	glutMouseFunc(MouseButton);

	glutMainLoop(); // vong lap doi de xu li cac su kien tiep theo

	return 1;
}
