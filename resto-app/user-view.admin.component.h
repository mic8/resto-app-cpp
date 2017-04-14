#pragma once

#include "data.component.h"

#include "user.model.h"
#include "role.model.h"
#include "user.provider.h"
#include "user-logged.model.h"
#include "user.admin.component.h"
#include "user-detail.admin.component.h"

class UserViewAdminComponent: DataComponent {
	
private:
	stringstream titleView;

	vector<UserModel> users;

	UserModel user;

	RoleModel roleModel;

	UserProvider userProvider;

public:
	void bindUsers();

	void bindTitle();

	void bindList();

	string header();

	void action(int currIndex);

	void init();

};