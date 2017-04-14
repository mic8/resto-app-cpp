#pragma once

#include "menu.component.h"
#include "user.model.h"
#include "role.model.h"
#include "user.provider.h"

#include "vendor.admin.component.h"
#include "user-add.admin.component.h"
#include "user-view.admin.component.h"

class UserAdminComponent: MenuComponent {

private:
	UserProvider userProvider;

public:
	void bindList();

	void bindTitle(string title);

	void addUser();

	void viewUsers();

	void action(int currIndex);

	void back();

	void init();
	
};