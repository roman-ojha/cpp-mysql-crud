#include <iostream>

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
	std::string table_name = "user";
	User() {}
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

	// Defines inside 'App.h'
	void migrate();
	bool save();
};

#endif