#include <iostream>
#include <fstream>

#include "models/User.cpp"
#include "config/Database.cpp"

class App
{
public:
	static Database *db;
	std::string name;
	User authenticatedUser;
	App(std::string name) : name(name){}
	~App() {
		delete db;
	}
	void run()
	{
		this->home();
	}

private:
	bool authenticateUser()
	{
		try
		{
			std::string email;
			std::ifstream in("token.txt");
			in >> email;
			sql::ResultSet *res = App::db->query("SELECT * FROM user WHERE email='" + email + "'");
			if (!res->next())
			{
				std::cout << "Unauthorized Please login first" << std::endl;
				return false;
			}
			if (email == res->getString("email"))
			{
				// Authorized
				int id = res->getInt(1);
				std::string name = res->getString("name");
				std::string email = res->getString("email");
				std::string address = res->getString("address");
				std::string password = res->getString("password");
				User user(id, name, email, address, password);
				this->authenticatedUser = user;
				return true;
			}
		}
		catch (sql::SQLException &e)
		{
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		}
		return false;
	}
	void createNewUer()
	{
	}
	void viewProfile()
	{
	}
	void listOfUsers()
	{
	}
	void updateProfile()
	{
	}
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
				case 1:
					this->createNewUer();
					break;
				case 2:
					this->viewProfile();
					break;
				case 3:
					this->listOfUsers();
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
			this->signUp();
		}
	}

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

bool User::save()
{
	sql::ResultSet *res = App::db->query("INSERT INTO " + this->table_name + " (name, email, address, password)"
																			 " VALUES('" +
										 this->name + "', '" + this->email + "', '" + this->address + "', '" + this->password + "');");
	if (res)
	{
		delete res;
		return true;
	}
	else
		return false;
}

void User::migrate() {
	std::string create_user = "CREATE TABLE User("
		"id INT(10) AUTO_INCREMENT PRIMARY KEY,"
		"name VARCHAR(50) NOT NULL,"
		"email VARCHAR(50) NOT NULL,"
		"address VARCHAR(50) NOT NULL,"
		"password VARCHAR(50) NOT NULL)";
	try
	{
		sql::ResultSet* res = App::db->query(create_user);
		delete res;
	}
	catch (...)
	{
		// std::cout << "# ERR: " << e.what();
		// std::cout << " (MySQL error code: " << e.getErrorCode();
		// std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
}