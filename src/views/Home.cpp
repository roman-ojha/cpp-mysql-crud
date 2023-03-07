#include<iostream>
#include "Profile.cpp"
#include "User.cpp"
//#include "SignUp.cpp"

class Home:public Profile ,public UserView{
public:
	void home()
	{
		bool res = this->authenticateUser();
		if (res)
		{
			std::cout << "==================== Hello, " + std::string(this->authenticatedUser.name) + " Welcome ====================" << std::endl;
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
			//this->signUp();
		}
	}
};