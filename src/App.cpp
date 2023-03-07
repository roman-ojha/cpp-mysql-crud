#include <iostream>
#include <fstream>

#include "models/User.cpp"
#include "config/Database.cpp"
#include "views/Home.cpp"

class App: private Home
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