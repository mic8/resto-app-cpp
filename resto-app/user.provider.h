#pragma once

#include "provider.h"

#include "user.model.h"
#include "user-logged.model.h"

using namespace std;

class UserProvider : Provider {

private:
	vector<UserModel> users;
	UserModel user;

public:
	UserProvider();

	void bindUsers();

	void bindUser();

	void setResult();

	vector<UserModel> all();

	bool add(UserModel user);

	bool remove(UserModel user);

	bool update(UserModel user);

	int getIndex(int id);

	UserModel findById(int id);

	UserModel findByUsername(string username);

	UserModel last();

	bool hasById(int id);

	bool hasByUsername(string username);

};