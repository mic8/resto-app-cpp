#pragma once

#include "menu.component.h"
#include "user.model.h"
#include "user-logged.model.h"
#include "user.provider.h"

#include "user.admin.component.h"
#include "menu.admin.component.h"
#include "auth.component.h"
#include "transaction.admin.component.h"

class VendorAdminComponent: MenuComponent {

private:
	UserModel userLogged;

	UserProvider userProvider;

	void bindLoggedUser();

	void bindList();

	void bindTitle(string title);

	void doManageUser();

	void doManageMenu();

	void doManageTransaction();

	void doLogout();

	void action(int currIndex);

public:
	void init();

};