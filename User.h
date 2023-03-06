#include<iostream>

class User {

private:
	int id;
	std::string password;
public:
	std::string name;
	std::string email;
	std::string address;
	std::string table_name = "User";
	User(std::string _name, std::string _email, std::string _address, std::string _pass) {
		this->name = _name;
		this->email = _email;
		this->address = _address;
		this->password = _pass;
	}
	bool save();

};
