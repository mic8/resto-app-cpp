#pragma once

#include "component.h"

#include "menu.model.h"
#include "menu.provider.h"

#include "select.component.h"
#include "menu.admin.component.h"

class MenuAddAdminComponent : Component {

private:
	MenuProvider menuProvider;

public:
	void doSubmit(string name, double price, int qty);

	void success();

	void error();

	void init();

};