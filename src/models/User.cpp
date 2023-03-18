#include <iostream>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

#ifndef USER
#define USER
class User
{

private:
	int id;
	std::string password;

public:
	std::string name;
	std::string email;
	std::string address;
	static std::string table_name;
	User()
	{
		this->name = "";
		this->email = "";
		this->address = "";
	}
	User(std::string _name, std::string _email, std::string _address, std::string _pass)
	{
		this->id = NULL;
		this->name = _name;
		this->email = _email;
		this->address = _address;
		this->password = _pass;
	}
	User(int _id, std::string _name, std::string _email, std::string _address, std::string _pass)
	{
		this->id = _id;
		this->name = _name;
		this->email = _email;
		this->address = _address;
		this->password = _pass;
	}

	static sql::ResultSet* all();
	// Defines inside 'App.h'
	void migrate();
	bool save();
};

#endif