#pragma once

#include "component.h"
#include "user.provider.h"
#include "role.model.h"
#include "auth.component.h"

class RegisterComponent: Component {

private:
	UserProvider userProvider;

public:
	void doRegister(string username, string name, string password, int role);

	void success();

	void error();

	void init();

};