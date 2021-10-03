#include <iostream>
#include "Header/functionSQL.h"
#include "Header/libraryFun.h"
#include "Header/openGL.h"
using namespace std;

int main1()
{
	//library l{};
	////l.classifyCategory("XXX");
	//
	//vector<vector<string>> lb = l.searchBook("Ah");
	//for (size_t i = 0; i < lb.size(); i++)
	//{
	//	for (size_t j = 0; j < lb[i].size(); j++)
	//		cout << lb[i][j] << endl;
	//	cout << endl;
	//}

	member Mem{};
	Mem.registerMember("Phat Pham", 20127680);
	
	
	return 0;
}

int main(int argc, char** argv) {

	glutInit(&argc, argv); // khoi tao glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // thiet lap che do mau

	glutInitWindowSize(1180, 750);// thiet lap kich thuoc cua so

	glutInitWindowPosition(0, 0);// vi tri cua so tai toa do 0 0 cua man hinh

	glutCreateWindow("Library Management");

	glutReshapeFunc(ReShape);

	Init(); // ham de thiet lap cau hinh openGL

	glutDisplayFunc(RenderScene);// khi cua so man hinh hien thi

	glutMouseFunc(MouseButton);

	glutMainLoop(); // vong lap doi de xu li cac su kien tiep theo

	return 1;
}
