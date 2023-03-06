#include <iostream>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

/*
	*) Steps:
		-> first we have to download mysqli connector
		-> https://dev.mysql.com/downloads/connector/cpp/
		-> https://github.com/agusk/crud-mysql-cpp/blob/master/src/demo-connection.cpp
		-> https://github.com/rohanparab/cppMySQL/blob/master/main.cpp
		-> https://youtu.be/a_W4zt5sR1M
*/

class Database
{
};

int main()
{
	try
	{
		sql::Driver *driver;
		sql::Connection *conn;
		std::cout << "Connecting to mysql server...";
		driver = get_driver_instance();
		conn = driver->connect("tcp://127.0.0.1:3306", "root", "");
		std::cout << "Connected" << std::endl;
		delete conn;
	}
	catch (sql::SQLException &e)
	{
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
}
