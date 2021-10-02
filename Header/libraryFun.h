#pragma once
#pragma warning(disable:4996)

#include "functionSQL.h"
#include "g_class.h"

bool library::checkStatusBook(string idBook)
{
	string select("SELECT * FROM BOOK WHERE IDBook = '" + idBook + "'");
	selectData(dirLibrary, select);
	if (listBook[0][3] == "0")
		return false;
	return true;
}

void library::removeBook(string idBook)
{
	string dataDelete("DELETE FROM COMPANY WHERE IDBook = '" + idBook + "'");
	deleteData(dirLibrary, dataDelete);
}

void library::classifyCategory(string category)
{
	string select("SELECT * FROM BOOK WHERE Category = '" + category + "'");
	selectData(dirLibrary, select);
	cout << "Danh sach the loai " << category << endl;
	for (int i = 0; i < listBook.size(); i++)
	{
		for (int j = 0; j < listBook[i].size(); j++)
			cout << listBook[i][j] << endl;
		cout << endl;
	}
}

vector<string> split(const string& s, const char delim)
{
	unsigned int i = 0;
	auto pos = s.find(delim);
	vector<string> v;
	while (pos != string::npos)
	{
		v.emplace_back(s.substr(i, pos - i));
		i = ++pos;
		pos = s.find(delim, pos);
	}
	if (pos == string::npos)
	{
		v.emplace_back(s.substr(i, s.length()));
	}

	return v;
}

void library::insertBook(book key, int quantity)
{
	//string name = key.idBook.substr(0, 4);
	string select("SELECT * FROM BOOK WHERE NAMEBOOK =" + key.getName() + ";");
	if (selectData(dirBook, select))
	{
		cout << "Insert succeed" << endl;
		// search từ name lấy ra 6 số ID cuối cùng
		// chuyển ID string -> int
		// gán cho ID key = 6 số last ID + 1
		// number += quantity

	}
	else
	{
		// Khởi tạo ID mới = 4 số ID last + 1
		// cập nhật thuộc tính vào table
		// 
	}
}

char* convertStr(string s) {
	int n = s.length();

	// declaring character array
	char* char_array = new char[n + 1];

	strcpy(char_array, s.c_str());
	return char_array;
}

vector<vector<string>> library::sortBookName() {
	char t[50]{};
	string select("SELECT * FROM BOOK ORDER BY Namebook ASC");
	selectData(dirLibrary, select);
	
	return listBook;
}

vector<vector<string>> library::searchBook(string nameBook) {
	vector<vector<string>> a;
	string select("SELECT * FROM BOOK WHERE Namebook GLOB '*" + nameBook + "*'");
	selectData(dirLibrary, select);
	if (listBook.size() > 0)
		return listBook;
	return a;
}

vector<vector<string>>  member::sortMember() {
	char t[50];
	string select("SELECT * FROM MEMBER ORDER BY FULLNAME ASC ");
	selectData(dirLibrary, select);
	
	return listBook;
}

int member::registerMember(string fullName, int id) {
	string select("SELECT * FROM MEMBER WHERE FULLNAME = '" + fullName + "' AND IDMember = '" + to_string(id) + "'");
	string sql("SELECT * FROM MEMBER;");
	selectData(dirLibrary, sql);

	if (checkExist(dirLibrary, "MEMBER", fullName, 1)) {
		// thong bao da co tai khoan
		cout << "account already existed!\n ";
		return 0;
	}
	else {
		string data("INSERT INTO MEMBER (FULLNAME, IDMember, DateCreateCard) VALUES('" + fullName + "', '" + to_string(id) +"', '" + "2007-01-01" + "');");
		
		return insertData(dirLibrary, data);

	}
}