#ifndef _G_CLASS_H_
#define _G_CLASS_H_

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
   bool checkStatusBook();  // đặng tiến đạt
   void insertBook();   //lê tấn đạt
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

#endif _G_CLASS_H_