#pragma once

#include <iostream>
#include <string>

using namespace std;

class UserModel {

protected :
	int id;
	string username;
	string name;
	string password;
	int role;

public :
	int getId();

	void setId(int id);

	string getUsername();

	void setUsername(string username);

	string getName();
	
	void setName(string name);

	string getPassword();

	void setPassword(string password);

	int getRole();

	void setRole(int role);

};