#pragma once

#include <iostream>
#include <vector>
using std::string;
using std::vector;

struct date
{
	int day, month, year;
};

class library
{
private:
	int password;
	vector<class book> listBook;
	vector<class member> listMember;

public:
	//book
	virtual bool checkStatusBook() = 0;  // đặng tiến đạt
	virtual void insertBook() = 0;   //lê tấn đạt
	virtual vector<class book> searchBook() = 0; // phạm thị ánh phát
	virtual void removeBook() = 0; // đặng tiến đạt
	virtual void sortBookId() = 0;   //lê tấn đạt
	virtual void sortBookName() = 0; // phạm thì ánh phát
	virtual void classifyCategory() = 0; // đặng tiến đạt
	virtual void outOfDateBorrow() = 0; // lê tấn đạt

	//member
	virtual void registerMember() = 0; //phạm thị ánh phát
	virtual void sortMember() = 0;
};

class book // dai dien cho 1 loai sach ( vi du sach A co 20q)
{
protected:
	string nameBook;
	string idBook;
	string category; // thể loại
	char condition;  // 'o' : cũ, 'n' : mới
	string author;   // tác giả
	int number;      //so luong
public:
};

class member
{
protected:
	string fullname;
	int idMember;
	date dateCreateCard;

public:
};

class cardBorrow
{
private:
	int idCardBorrow;
	int timeoutBorrow; // số ngày mượn sách
	date returnDate;
	member c_member;
	book c_book;

public:
};