#pragma once

#include "menu.component.h"
#include "menu.model.h"
#include "menu.provider.h"

#include "vendor.admin.component.h"
#include "menu-add.admin.component.h"
#include "menu-view.admin.component.h"

class MenuAdminComponent : MenuComponent {

private:
	MenuProvider menuProvider;

public:
	void bindList();

	void bindTitle(string title);

	void addMenu();

	void viewMenus();

	void action(int currIndex);

	void back();

	void init();

};