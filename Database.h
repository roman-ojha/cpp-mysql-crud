#include<iostream>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

class Database
{
private:
	std::string hostname;
	std::string user;
	std::string password;
	std::string databasename;
	sql::Driver* driver;
	sql::Connection* conn;

public:
	Database(std::string _hostname, std::string _user, std::string _password, std::string _dbname) {
		this->hostname = _hostname;
		this->user = _user;
		this->password = _password;
		this->databasename = _dbname;
		try {

			// std::cout << "Connecting to mysql server...";
			driver = get_driver_instance();
			this->conn = driver->connect(this->hostname, this->user, this->password);
			// std::cout << "Database Connected" << std::endl;
			this->conn->setSchema(this->databasename);
		}
		catch (sql::SQLException& e)
		{
			if (e.getErrorCode() == 1049) {
				// Database doesn't exist so need to create database
				this->query("CREATE DATABASE " + std::string(this->databasename));
			}
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		}
	}
	void query(std::string _query_str) {
		try {
			sql::Statement* stmt = this->conn->createStatement();
			sql::ResultSet* res = stmt->executeQuery(_query_str);
			std::cout << res->first() << std::endl;
		}
		catch (sql::SQLException& e) {
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		}
	}

	void migrate() {
		std::string create_user = "CREATE TABLE User("
			"id INT(10) AUTO_INCREMENT PRIMARY KEY,"
			"name VARCHAR(50) NOT NULL,"
			"email VARCHAR(50) NOT NULL,"
			"address VARCHAR(50) NOT NULL,"
			"password VARCHAR(50) NOT NULL)";
		try {
			sql::Statement* stmt = this->conn->createStatement();
			sql::ResultSet* res = stmt->executeQuery(create_user);
			std::cout << res->first() << std::endl;
		}
		catch (sql::SQLException& e) {
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		}
	}

	~Database() {
		std::cout << "Database closed" << std::endl;
		delete conn;
	}
};
