#include <iostream>
#include "Header/functionSQL.h"
#include "Header/libraryFun.h"

using namespace std;

int main()
{
	string s ("INSERT INTO CARD VALUES (0002, 10 , '2021-12-30', 20127011, 'TC0102')");
	insertData(dirLibrary, s);
	return 0;
}
