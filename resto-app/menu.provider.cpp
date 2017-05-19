#include "menu.provider.h"

MenuProvider::MenuProvider() {
	this->setPath("menu.csv");
	this->bindMenus();
	this->bindMenu();
}

void MenuProvider::bindMenus() {
	int i;
	for (i = 0; i < this->files().size(); i++) {
		MenuModel menuModel;
		menuModel.setId(stoi(this->files()[i][0]));
		menuModel.setName(this->files()[i][1]);
		menuModel.setPrice((double) stoi(this->files()[i][2]));
		menuModel.setQty(stoi(this->files()[i][3]));

		this->menus.push_back(menuModel);
	}
}

void MenuProvider::bindMenu() {
	this->menu.setId(0);
	this->menu.setName("");
	this->menu.setPrice(0);
	this->menu.setQty(0);
}

void MenuProvider::setResult() {
	int i;
	for (i = 0; i < this->menus.size(); i++) {
		this->result.push_back(
			to_string(this->menus[i].getId()) + this->delimiter + this->menus[i].getName() + this->delimiter +
			to_string(this->menus[i].getPrice()) + this->delimiter +
			to_string(this->menus[i].getQty())
			);
	}
}

vector<MenuModel> MenuProvider::all() {
	return this->menus;
}

bool MenuProvider::add(MenuModel menu) {
	MenuModel last = this->last();
	menu.setId(last.getId() + 1);

	try {
		this->menus.push_back(menu);
		this->setResult();
		this->save();
		return true;
	}
	catch (exception e) {
		return false;
	}
}

bool MenuProvider::remove(MenuModel menu) {
	try {
		this->menus.erase(this->menus.begin() + this->getIndex(menu.getId()));
		this->setResult();
		this->save();
		return true;
	}
	catch (exception e) {
		return false;
	}
}

bool MenuProvider::update(MenuModel menu) {
	try {
		int index = this->getIndex(menu.getId());
		this->menus[index].setName(menu.getName());
		this->menus[index].setPrice(menu.getPrice());
		this->menus[index].setQty(menu.getQty());

		this->setResult();
		this->save();

		return true;
	}
	catch (exception e) {
		return false;
	}
}

bool MenuProvider::updateQty(int id, int qty) {
	MenuModel menu = this->findById(id);
	menu.setQty(qty);

	return this->update(menu);
}

int MenuProvider::getIndex(int id) {
	int i;
	bool hasFounded = false;
	for (i = 0; i < this->menus.size(); i++) {
		if (this->menus[i].getId() == id) {
			hasFounded = true;
			break;
		}
	}

	if (hasFounded) {
		return i;
	}
	else {
		return NULL;
	}
}

MenuModel MenuProvider::findById(int id) {
	int i;
	bool hasFounded = false;
	for (i = 0; i < this->menus.size(); i++) {
		if (this->menus[i].getId() == id) {
			hasFounded = true;
			break;
		}
	}

	if (hasFounded) {
		return this->menus[i];
	}
	else {
		return this->menu;
	}
}

MenuModel MenuProvider::last() {
	if (this->menus.size() == 0) {
		return this->menu;
	}
	else {
		return this->menus[this->menus.size() - 1];
	}
}

bool MenuProvider::hasById(int id) {
	MenuModel menu;
	menu = this->findById(id);

	if (menu.getId()) {
		return true;
	}

	return false;
}