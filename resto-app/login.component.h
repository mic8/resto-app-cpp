#pragma once

#include "component.h"
#include "user.provider.h"
#include "role.model.h"
#include "vendor.admin.component.h"
#include "vendor.waiter.component.h"
#include "user-logged.model.h"

class LoginComponent: Component {

private:
	UserProvider userProvider;

public:
	void doLogin(UserModel user, string password);

	void doLoggedAsAdmin();

	void doLoggedAsWaiter();

	void success(string message);

	void error(string message);

	void init();

};