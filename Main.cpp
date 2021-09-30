#include <iostream>
#include "Header/functionSQL.h"
#include "Header/libraryFun.h"

using namespace std;

int main()
{
	library l;
	vector<vector<string>> lb = l.searchBook("L");
	for (size_t i = 0; i < lb.size(); i++)
	{
		for (size_t j = 0; j < lb[i].size(); j++)
			cout << lb[i][j] << endl;
		cout << endl;
	}

	return 0;
}
