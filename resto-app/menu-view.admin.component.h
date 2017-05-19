#pragma once

#include "data.component.h"

#include "menu.model.h"
#include "menu.provider.h"
#include "menu.admin.component.h"
#include "menu-detail.admin.component.h"

class MenuViewAdminComponent : DataComponent {

private:
	stringstream titleView;

	vector<MenuModel> menus;

	MenuModel menu;

	MenuProvider menuProvider;

public:
	void bindMenus();

	void bindTitle();

	void bindList();

	string header();

	void action(int currIndex);

	void init();

};