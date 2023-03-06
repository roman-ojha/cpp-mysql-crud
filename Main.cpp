#include <iostream>
#include "App.cpp"

/*
	*) Steps:
		-> first we have to download mysqli connector
		-> https://dev.mysql.com/downloads/connector/cpp/
		-> https://github.com/agusk/crud-mysql-cpp/blob/master/src/demo-connection.cpp
		-> https://github.com/rohanparab/cppMySQL/blob/master/main.cpp
		-> https://youtu.be/a_W4zt5sR1M
*/

int main()
{
	App app("cpp_curd");
	app.run();
	return 0;
}
