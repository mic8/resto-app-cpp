#pragma once

#include "component.h"

#include "user.model.h"
#include "user.provider.h"
#include "role.model.h"

#include "select.component.h"
#include "user.admin.component.h"

class UserAddAdminComponent: Component {

private:
	UserProvider userProvider;

public:
	void doSubmit(string username, string name, string password, int role);

	void success();

	void error();

	void init();

};