#include<iostream>
#include<fstream>

#ifndef USER
#include "../src/models/User.cpp"
#define USER
#endif

class SignUp {
public:
	void signUp()
	{
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
		if (user.save())
		{
			std::cout << "User register successfully" << std::endl;
			std::ofstream out("token.txt");
			out << email;
		}
		else
			std::cout << "Error while registering user" << std::endl;
	}
};