#include <iostream>
#include "Header/functionSQL.h"
#include "Header/libraryFun.h"

using namespace std;

int main()
{
	library l{};
	l.classifyCategory("XXX");

	/*vector<string> s = l.searchBook("AD30CF");

	for (int i = 0;i < s.size();i++) {
		cout << s[i] << endl;
	}*/

	member Mem{};

	cout << Mem.registerMember("tandat", 20127011);
	/*vector<vector<string>> s = Mem.sortMember();
	for (int i = 0;i < s.size();i++) {
		cout << s[i][1] << endl;
	}*/
	return 0;
}
