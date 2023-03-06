#include<iostream>
#include "User.h"
#include "Database.h"

class App {
public:
	static Database* db;
	std::string name;
	App(std::string name) :name(name) {
	};
	void run() {

		this->signUp();
	}

private:
	void signUp() {
		std::string password;
		std::string name;
		std::string email;
		std::string address;
		std::cout << "Sign UP: ==============================" << std::endl;
		std::cout << "Enter the following fields: " << std::endl;
		std::cout << "Name: ";
		std::cin >> name;
		std::cout << "Email: ";
		std::cin >> email;
		std::cout << "Address: ";
		std::cin >> address;
		std::cout << "Password: ";
		std::cin >> password;
		User user(name, email, address, password);
		if (user.save()) std::cout << "User register successfully" << std::endl;
		else std::cout << "Error while registering user" << std::endl;
	}
};

bool User::save() {
	App::db->query("INSERT INTO " + this->table_name + " (name, email, address, password)"
		"VALUES(" + this->name + ", " + this->email + ", " + this->address + ", " + this->password + ");"
	);
	return true;
}