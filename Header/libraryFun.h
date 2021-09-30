#pragma once

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
		{
			cout << listBook[i][j] << endl;
		}
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
	string select("SELECT * FROM BOOK WHERE NAMEBOOK =" + key.nameBook + ";");
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

