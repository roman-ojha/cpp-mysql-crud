#include <iostream>
#include <fstream>
#include <windows.h>

#include "models/User.cpp"
#include "config/Database.cpp"
#include "views/Home.cpp"

#ifndef AUTHENTICATEDUSER
#include "utils/AuthenticatedUser.cpp"
#define AUTHENTICATEDUSER
#endif

class App
{
public:
	static Database *db;
	std::string name;
	User authenticatedUser;
	App(std::string &_name){
		this->name = _name;
		SetConsoleTitleA(_name.c_str());
	}
	~App()
	{
		delete db;
	}
	void run()
	{
		// User u;
		// u.migrate();
		AuthenticatedUser *authUser = this->authenticateUser();
		Home h;
		h.home(authUser);
	}

private:
	AuthenticatedUser *authenticateUser()
	{
		try
		{
			std::string email;
			std::ifstream in("token.txt");
			in >> email;
			sql::ResultSet *res = App::db->query("SELECT * FROM users WHERE email='" + email + "'");
			if (res->rowsCount() == 0)
			{
				std::cout << "Unauthorized Please login first ========" << std::endl;
				AuthenticatedUser *authUser = new AuthenticatedUser;
				return authUser;
			}
			res->next();
			if (email == res->getString("email"))
			{
				// Authorized
				int id = res->getInt(1);
				std::string name = res->getString("name");
				std::string email = res->getString("email");
				std::string address = res->getString("address");
				std::string password = res->getString("password");
				User *user = new User(id, name, email, address, password);
				AuthenticatedUser *authUser = new AuthenticatedUser(user);
				// this->authenticatedUser = user;
				return authUser;
			}
		}
		catch (sql::SQLException &e)
		{
			// std::cout << "# ERR: " << e.what();
			// std::cout << " (MySQL error code: " << e.getErrorCode();
			// std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		}

		AuthenticatedUser *authUser = new AuthenticatedUser;
		return authUser;
	}
};

// Defination of User model 
std::string User::table_name = "user";
bool User::save()
{
	try
	{

		sql::ResultSet *res = App::db->query("INSERT INTO " + User::table_name + " (name, email, address, password)"
																				 " VALUES('" +
											 this->name + "', '" + this->email + "', '" + this->address + "', '" + this->password + "');");
		delete res;
		return true;
	}
	catch (...)
	{
	}
	return false;
}

void User::migrate()
{
	std::string create_user = "CREATE TABLE Users("
							  "id INT(10) AUTO_INCREMENT PRIMARY KEY,"
							  "name VARCHAR(50) NOT NULL,"
							  "email VARCHAR(50) NOT NULL,"
							  "address VARCHAR(50) NOT NULL,"
							  "password VARCHAR(50) NOT NULL)";
	try
	{
		sql::ResultSet *res = App::db->query(create_user);
		delete res;
	}
	catch (...)
	{
	}
}

sql::ResultSet* User::all() {
	sql::ResultSet* res = App::db->query("SELECT * FROM " + User::table_name+";");
	int id;
	std::string name;
	std::string email;
	std::string address;
	std::string password;
	res->next();
	id = res->getInt(1);
	name = res->getInt("name");
	email = res->getInt("email");
	address = res->getInt("address");
	password = res->getInt("password");
	std::cout << id << "\t" << name << "\t" << email << "\t" << address << "\t" << password << std::endl;
	return res;
}

User *AuthView::signIn()
{
	std::string email;
	std::string password;
	std::system("cls");
	std::cout << "Sign In: ==============================" << std::endl;
	std::cout << "Enter the following fields: " << std::endl;
	std::cout << "Email: ";
	std::cin >> email;
	std::cout << "Password: ";
	std::cin >> password;
	User *user = new User("", email, "", password);
}