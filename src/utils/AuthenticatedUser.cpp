#include<iostream>

#ifndef USER
#include "../src/models/User.cpp"
#define USER
#endif

class AuthenticatedUser {
public:
	User *user;
	bool isAuthenticated;
	AuthenticatedUser() {
		this->user = nullptr;
		this->isAuthenticated = false;
	}
	AuthenticatedUser(User* _user) {
		this->user = _user;
		this->isAuthenticated = true;
	}
	~AuthenticatedUser() {
		delete user;
	}
};