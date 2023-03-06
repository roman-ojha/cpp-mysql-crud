#include<iostream>
#include "Database.cpp"

class App {
public:
	std::string name;
	App(std::string name) :name(name) {};
	void run() {
		Database* db = new Database("tcp://127.0.0.1:3306", "root", "", "cpp_curd");
	}
	void signUp() {
		
	}
};