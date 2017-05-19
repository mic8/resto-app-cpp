#pragma once

#include <iostream>
#include <vector>

using namespace std;

class RoleModel {

private:
	void bindRoles();
	
	void bindRoleLabels();

public:
	RoleModel();

	static const int ADMIN = 1;

	static const int WAITER = 2;

	//static const int CUSTOMER = 3;
	
	vector<int> roles;

	vector<string> roleLabels;

};