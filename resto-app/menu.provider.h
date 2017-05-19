#pragma once

#include "provider.h"

#include "menu.model.h"

using namespace std;

class MenuProvider : Provider {

private:
	vector<MenuModel> menus;
	MenuModel menu;

public:
	MenuProvider();

	void bindMenus();

	void bindMenu();

	void setResult();

	vector<MenuModel> all();

	bool add(MenuModel menu);

	bool remove(MenuModel user);

	bool update(MenuModel user);

	bool updateQty(int id, int qty);

	int getIndex(int id);

	MenuModel findById(int id);

	MenuModel last();

	bool hasById(int id);

};