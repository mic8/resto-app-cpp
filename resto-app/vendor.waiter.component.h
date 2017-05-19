#pragma once

#include "menu.component.h"
#include "user.model.h"
#include "user-logged.model.h"
#include "user.provider.h"

#include "menu.waiter.component.h"
#include "auth.component.h"

class VendorWaiterComponent : MenuComponent {

private:
	UserModel userLogged;

	UserProvider userProvider;

	void bindLoggedUser();

	void bindList();

	void bindTitle(string title);

	void doOrder();

	void doLogout();

	void action(int currIndex);

public:
	void init();

};