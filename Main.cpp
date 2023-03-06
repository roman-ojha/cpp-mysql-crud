#include <iostream>
#include "App.h"

constexpr auto DB_HOST = "tcp://127.0.0.1:3306";
constexpr auto DB_USER = "root";
constexpr auto DB_PASWORD = "";
constexpr auto DB_NAME = "cpp_crud";
/*
	-> first we have to download mysqli connector
	-> https://dev.mysql.com/downloads/connector/cpp/
	-> https://github.com/agusk/crud-mysql-cpp/blob/master/src/demo-connection.cpp
	-> https://github.com/rohanparab/cppMySQL/blob/master/main.cpp
	-> https://youtu.be/a_W4zt5sR1M
*/

Database *App::db = new Database(DB_HOST, DB_USER, DB_PASWORD, DB_NAME);
int main()
{
	App app("cpp_curd");
	app.run();
	return 0;
}
