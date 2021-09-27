#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include "Header/functionSQL.h"

using namespace std;

const char* dirBook = R"(.\Database\Book.db)";
const char* dirMember = R"(.\Database\Member.db)";

int main()
{
	createDB(dirBook);
	createTable(dirBook, "book");
	string sql("INSERT INTO BOOK (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Alice', 'Chapa', 35, 'Tampa', 'A');"
		"INSERT INTO BOOK (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Bob', 'Lee', 20, 'Dallas', 'B');"
		"INSERT INTO BOOK (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Fred', 'Cooper', 24, 'New York', 'C');");
	insertData(dirBook, sql);

	createDB(dirMember);
	createTable(dirMember, "member");

	//deleteData(dir); // use prior to insert
	//insertData(dir); // uncomment the deleteData above to avoid duplicates
	//updateData(dir);
	//selectData(dir);

	return 0;
}
