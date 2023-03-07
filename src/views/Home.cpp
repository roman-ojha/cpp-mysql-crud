#include<iostream>
#include "Profile.cpp"
#include "UserView.cpp"
#include "SignUp.cpp"

#ifndef USER
#include "../src/models/User.cpp";
#define USER
#endif

#ifndef AUTHENTICATEDUSER
#include "../src/utils/AuthenticatedUser.cpp";
#define AUTHENTICATEDUSER
#endif

class Home:private Profile ,private UserView,private SignUp{
public:
	void home(AuthenticatedUser *authUser)
	{
		if(authUser->isAuthenticated)
		{
			std::cout << "==================== Hello, " + std::string(authUser->user->name) + " Welcome ====================" << std::endl;
			int choice = 0;
			while (true)
			{
				std::cout << "Create new user (1): " << std::endl;
				std::cout << "View Profile (2): " << std::endl;
				std::cout << "List of Users & it's Operations (3): " << std::endl;
				std::cout << "Update your Profile (4)" << std::endl;
				std::cout << "Close program (5)" << std::endl;
				std::cout << "Choose between 1-5: ";
				std::cin >> choice;
				switch (choice)
				{
				case 1:;
					this->createNewUser();
					break;
				case 2:
					this->viewProfile();
					break;
				case 3:
					this->usersInfo();
					break;
				case 4:
					this->updateProfile();
					break;
				case 5:
					exit(1);
					break;
				default:
					std::cout << "Invalid Number, please pick it again:" << std::endl;
					break;
				}
			}
		}
		else
		{
			User *user = this->signUp();
			if (user) {
				AuthenticatedUser* authUser = new AuthenticatedUser(user);
				this->home(authUser);
			}
			else exit(1);
		}
	}
};