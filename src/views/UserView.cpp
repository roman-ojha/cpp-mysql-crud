#include <iostream>

#ifndef AUTHENTICATEDUSER
#include "../src/utils/AuthenticatedUser.cpp";
#define AUTHENTICATEDUSER
#endif

#ifndef USER
#include "../models/User.cpp";
#define USER
#endif

class UserView
{
public:
	void usersInfo(AuthenticatedUser *authUser)
	{
		std::system("cls");
		if (authUser->isAuthenticated) {
			sql::ResultSet *res = User::all();
			//int id;
			//std::string name;
			//std::string email;
			//std::string address;
			//std::string password;
			//std::cout << "Id\tName\tEmail\tAddress\tPassword" << std::endl;
			//res->next();
			//id = res->getInt(1);
			//name = res->getInt("name");
			//email = res->getInt("email");
			//address = res->getInt("address");
			//password = res->getInt("password");
			//std::cout << id << "\t" << name << "\t" << email << "\t" << address << "\t" << password << std::endl;
			//int choice;
			//std::cout << "Press '1' to go into home\nPress '2' to exist\n" << std::endl;
			//std::cin >> choice;
		}
		else {
			std::cout << "Unauthorized user!!!, please login first" << std::endl;
		}
	}
	void createNewUser()
	{
	}
};