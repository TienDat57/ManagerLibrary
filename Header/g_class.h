#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using std::string;
using std::vector;

struct date
{
	int day, month, year;
};

class book // dai dien cho 1 loai sach ( vi du sach A co 20q)
{
private:
	string nameBook;
	string idBook;
	string category; // thể loại
	char condition;  // 'o' : cũ, 'n' : mới
	string author;   // tác giả
	bool status;     // duoc muon hay chua
public:
	book(string name, string id) {
		this->nameBook = name;
		this->idBook = id;
	}

	string getName() {
		return this->nameBook;
	}
};

class library
{
private:
	int password;
	//vector<book> listBook;
	//vector<member> listMember;

public:
	//book
	bool checkStatusBook(string idBook);  // đặng tiến đạt

	void insertBook(book key, int quantity);   //lê tấn đạt

	vector<vector<string>> searchBook(string nameBook); // phạm thị ánh phát

	void removeBook(string idBook); // đặng tiến đạt

	//void sortBookId();   //lê tấn đạt

	vector<vector<string>> sortBookName(); // phạm thị ánh phát

	void classifyCategory(string category); // đặng tiến đạt

	//void outOfDateBorrow(); // lê tấn đạt

	//member
	//int registerMember(string fullName, int id); //phạm thị ánh phát
	//void sortMember();
};

class member
{
private:
	string fullname;
	int idMember;
	date dateCreateCard;
	int numOfBorrowedBook;

public:

	void setFullname(string name) {
		this->fullname = name;
	}

	string getName() {
		return this->fullname;
	}

	int getId() {
		return idMember;
	}

	void setID(int id) {
		this->idMember = id;
	}

	vector<vector<string>> sortMember();

	int registerMember(string fullName, int id);
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





