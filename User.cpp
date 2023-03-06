#include<iostream>

class User {
private:
	int id;
	std::string password;
public:
	std::string name;
	std::string email;
	std::string address;
	User(int _id, std::string _pass, std::string _name, std::string _email, std::string _address) {
		this->id = _id;
		this->name = _name;
		this->email = _email;
		this->address = _address;
		this->password = _pass;
	}
};