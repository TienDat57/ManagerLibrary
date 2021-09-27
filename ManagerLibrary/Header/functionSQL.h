#pragma once
#include <iostream>
#include <sqlite3.h>

using namespace std;

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

static int createTable(const char* dir, string databaseName)
{
	sqlite3* DB;
	char* messageError;
	string sql;
	if (databaseName == "book")
	{
		sql = "CREATE TABLE IF NOT EXISTS BOOK("
			"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
			"NAME      TEXT NOT NULL, "
			"LNAME     TEXT NOT NULL, "
			"AGE       INT  NOT NULL, "
			"ADDRESS   CHAR(50), "
			"GRADE     CHAR(1) );";
	}
	else if (databaseName == "member")
	{
		sql = "CREATE TABLE IF NOT EXISTS MEMBER("
			"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
			"NAME      TEXT NOT NULL, "
			"LNAME     TEXT NOT NULL, "
			"AGE       INT  NOT NULL, "
			"ADDRESS   CHAR(50), "
			"GRADE     CHAR(1) );";
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

	/*string sql("INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Alice', 'Chapa', 35, 'Tampa', 'A');"
		"INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Bob', 'Lee', 20, 'Dallas', 'B');"
		"INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Fred', 'Cooper', 24, 'New York', 'C');");*/

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
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
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
	}
	else
		cout << "Records selected Successfully!" << endl;

	return 0;
}

// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		// column name and value
		cout << azColName[i] << ": " << argv[i] << endl;
	}
	cout << endl;
	return 0;
}