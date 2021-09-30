﻿#pragma once
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
	char t [50];
	string select("SELECT * FROM BOOK"); 
	selectData(dirLibrary, select);
	for (int i = 1; i < listBook.size(); i++)
	{
		for (int j = 1; j < listBook.size(); j++)
		{
			if (strcmp(&convertStr(listBook[i][0])[j - 1], &convertStr(listBook[i][0])[j]) > 0)
			{
				strcpy(t, &convertStr(listBook[i][0])[j - 1] );
				strcpy(&convertStr(listBook[i][0])[j - 1], &convertStr(listBook[i][0])[j]);
				strcpy(&convertStr(listBook[i][0])[j], t);
			}
		}
	}
	return listBook;
}

vector<string> library::searchBook( string nameBook) {
	vector<string> a;
	string select("SELECT * FROM BOOK WHERE Category = '" + nameBook + "'");
	if (selectData(dirLibrary, select)) {
		for (int i = 0;i < listBook.size();i++) {
			if (listBook[i][0] == nameBook) {
				return listBook[i];
			}
		}
	}
	else {
		return a;
	}
	
	
}

vector<vector<string>>  member::sortMember() {
	char t[50];
	string select("SELECT * FROM MEMBER ");
	selectData(dirLibrary, select);
	for (int i = 1; i < listBook.size(); i++)
	{
		for (int j = 1; j < listBook.size(); j++)
		{
			if (strcmp(&convertStr(listBook[i][0])[j - 1], &convertStr(listBook[i][0])[j]) > 0)
			{
				strcpy_s(t, &convertStr(listBook[i][0])[j - 1]);
				strcpy(&convertStr(listBook[i][0])[j - 1], &convertStr(listBook[i][0])[j]);
				strcpy(&convertStr(listBook[i][0])[j], t);
			}
		}
	}
	return listBook;
}

int member::registerMember(string fullName, int id) {

	string select("SELECT FULLNAME, IDMember FROM BOOK WHERE FULLNAME = '" + fullName + /*"' AND IDMember = '" + to_string(id) +*/ "'");
	if (selectData(dirLibrary, select)) {
		// thong bao da co tai khoan
		return 0;
	}
	else {
		string data("INSERT INTO MEMBER (FULLNAME, IDMember, DateCreateCard) VALUES('phatxindep', 203943, 'now');");

		/*string data("INSERT INTO MEMBER (FULLNAME, IDMember, DateCreateCard) VALUES( '");
		data += fullName;
		data += ", '";
		data += to_string(id);
		data += ", '";
		data += 'now';
		data += "');";*/
		return insertData(dirLibrary, data) ;
		
	}
}