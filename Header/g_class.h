#pragma once
#include <iostream>
#include <vector>
using std::string;
using std::vector;

struct date
{
	int day, month, year;
};

class book // dai dien cho 1 loai sach ( vi du sach A co 20q)
{
public:
	string nameBook;
	string idBook;
	string category; // thể loại
	char condition;  // 'o' : cũ, 'n' : mới
	string author;   // tác giả
	int number;      //so luong
public:
};

class library
{
private:
	int password;
	//vector<book> listBook;
	//vector<member> listMember;

public:
	//book
	bool checkStatusBook();  // đặng tiến đạt
	void insertBook(book key, int quantity);   //lê tấn đạt
	vector<class book> searchBook(); // phạm thị ánh phát
	void removeBook(); // đặng tiến đạt
	void sortBookId();   //lê tấn đạt
	void sortBookName(); // phạm thì ánh phát
	void classifyCategory(); // đặng tiến đạt
	void outOfDateBorrow(); // lê tấn đạt

	//member
	void registerMember(); //phạm thị ánh phát
	void sortMember();
};



class member
{
protected:
	string fullname;
	int idMember;
	date dateCreateCard;
	int numOfBook;

public:
};

class cardBorrow
{
private:
	int idCardBorrow;
	int timeoutBorrow; // số ngày mượn sách
	date returnDate;
	string c_member; // ID member mượn sách
	string c_book; // ID sách được mượn

public:
};