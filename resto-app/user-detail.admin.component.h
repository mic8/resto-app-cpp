#pragma once

#include "menu.component.h"
#include "user-view.admin.component.h"
#include "user.model.h"
#include "role.model.h"
#include "user.provider.h"
#include "user-edit.admin.component.h"

class UserDetailAdminComponent: MenuComponent {

private:
	UserModel user;

	RoleModel roleModel;

	UserProvider userProvider;

	string header();

public:
	void bindUser(UserModel user);

	void bindTitle();

	void bindList();

	void doDelete();

	void doEdit();

	void action(int currIndex);

	void init(UserModel user);

};