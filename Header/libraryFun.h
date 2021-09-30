#pragma once

#include "functionSQL.h"
#include "g_class.h"

bool library::checkStatusBook()
{
	
	string select("SELECT * FROM BOOK WHERE CONDITION = '0';");
	selectData(dirBook, select);
	return 0;
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

