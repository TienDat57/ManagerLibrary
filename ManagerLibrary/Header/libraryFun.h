#pragma once

#include "functionSQL.h"
#include "g_class.h"

bool library::checkStatusBook()
{
	string select("SELECT * FROM BOOK WHERE CONDITION = '0';");
	selectData(dirBook, select);
	return 0;
}
