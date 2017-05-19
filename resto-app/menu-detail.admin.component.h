#pragma once

#include "menu.component.h"
#include "menu-view.admin.component.h"
#include "menu.model.h"
#include "menu.provider.h"
#include "menu-edit.admin.component.h"

class MenuDetailAdminComponent : MenuComponent {

private:
	MenuModel menu;

	MenuProvider menuProvider;

	string header();

public:
	void bindMenu(MenuModel menu);

	void bindTitle();

	void bindList();

	void doDelete();

	void doEdit();

	void action(int currIndex);

	void init(MenuModel menu);

};