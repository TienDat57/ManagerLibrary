#pragma once

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

using namespace std;

const char* dirLibrary = R"(.\Database\Library.db)";
const char* dirBook = R"(.\Database\Book.db)";
vector<vector<string>> listBook; // all features

static int createDB(const char* dir);
static int createTable(const char* dir, string databaseName);
static int deleteData(const char* dir, string dataDelete);
static int insertData(const char* dir, string dataInsert);
static int updateData(const char* dir, string dataUpdate);
static int selectData(const char* s, string dataSelect);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);

static int createDB(const char* dir)
{
	sqlite3* DB;
	int exit = sqlite3_open(dir, &DB);
	sqlite3_close(DB);
	return 0;
}

static int createTable(const char* dir, string tableName)
{
	sqlite3* DB;
	char* messageError;
	string sql;
	if (tableName == "book")
	{
		sql = "CREATE TABLE IF NOT EXISTS BOOK("
			"IDBook		VARCHAR(6) NOT NULL, "
			"Namebook	TEXT NOT NULL, "
			"Category		TEXT NOT NULL, "
			"Condition		CHAR(1), "
			"Author		TEXT NOT NULL, "
			"Number		INT NOT NULL ); ";
	}
	else if (tableName == "member")
	{
		sql = "CREATE TABLE IF NOT EXISTS MEMBER("
			"IDMember		INT NOT NULL, "
			"FULLNAME      TEXT NOT NULL, "
			"DateCreateCard		DATE NOT NULL); ";
	}
	else if (tableName == "card")
	{
		sql = "CREATE TABLE IF NOT EXISTS CARD("
			"IDCard      INT NOT NULL, "
			"Timeout		INT NOT NULL, "
			"ReturnDate		DATE NOT NULL, "
			"IDMember		INT NOT NULL, "
			"IDBook		VARCHAR(6) NOT NULL ); ";
	}
	try
	{
		int exit = sqlite3_open(dir, &DB);
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

	return 0;
}

static int insertData(const char* dir, string dataInsert)
{
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(dir, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, dataInsert.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in insertData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records inserted Successfully!" << endl;

	return 0;
}

static int updateData(const char* dir, string dataUpdate)
{
	sqlite3* DB;
	char* messageError;

	//string sql("UPDATE GRADES SET GRADE = 'A' WHERE LNAME = 'Cooper'");

	int exit = sqlite3_open(dir, &DB);
	exit = sqlite3_exec(DB, dataUpdate.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in updateData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records updated Successfully!" << endl;

	return 0;
}

static int deleteData(const char* dir, string dataDelete)
{
	sqlite3* DB;
	char* messageError;

	//string sql = "DELETE FROM GRADES;";

	int exit = sqlite3_open(dir, &DB);
	exit = sqlite3_exec(DB, dataDelete.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in deleteData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records deleted Successfully!" << endl;

	return 0;
}

static int selectData(const char* dir, string dataSelect)
{
	sqlite3* DB;
	char* messageError;

	//string sql = "SELECT * FROM GRADES;";

	int exit = sqlite3_open(dir, &DB);
	exit = sqlite3_exec(DB, dataSelect.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error in selectData function." << endl;
		sqlite3_free(messageError);
		return 0;
	}
	else {
		cout << "Records selected Successfully!" << endl;
		return 1;
	}
}

static int checkExist(const char* dir, string object, string data, int idx) { // idx: 0_id  1_name
	string sql("SELECT * FROM " + object+ ";");
	selectData(dirLibrary, sql);
	for (int i = 0;i < listBook.size();i++) {
		if (listBook[i][idx] == data) {
			return 1;
		}
	}
	return 0;
}


static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	vector <string> temp;
	for (int i = 0; i < argc; i++)
		temp.push_back(argv[i]);
	listBook.push_back(temp);
	for (int i = 0; i < temp.size(); i++)
		temp.pop_back();
	return 0;
}


