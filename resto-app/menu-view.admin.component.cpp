#include "menu-view.admin.component.h"

void MenuViewAdminComponent::bindMenus() {
	this->menus = this->menuProvider.all();
}

void MenuViewAdminComponent::bindTitle() {
	this->titleView << this->header() << endl;
	this->titleView << "  | #ID |   \t\tMenu Name\t\t   |   \t\tPrice\t\t   |   \tQuantity   |" << endl;
	this->titleView << this->header();
}

void MenuViewAdminComponent::bindList() {
	int i;
	for (i = 0; i < this->menus.size(); i++) {
		stringstream list;
		list << "| " << setw(3) << this->menus[i].getId() << " | "
			<< setiosflags(ios::left) << setw(40) << this->menus[i].getName() << " | "
			<< setw(29) << this->menus[i].getPrice() << " | "
			<< setiosflags(ios::right) << setw(13) << this->menus[i].getQty()
			<< " | " << endl;
		list << this->header();
		list.unsetf(StreamHelper::UNSET);

		this->addList(list.str());
	}
}

string MenuViewAdminComponent::header() {
	return "  --------------------------------------------------------------------------------------------------";
}

void MenuViewAdminComponent::action(int currIndex) {
	if (this->isBack) {
		MenuAdminComponent menuAdminComponent;
		menuAdminComponent.init();
	}
	else if (this->isExit) {
		this->menu = this->menus[this->getCurrIndex()];
		MenuDetailAdminComponent menuDetailAdminComponent;
		menuDetailAdminComponent.init(this->menu);
	}
}

void MenuViewAdminComponent::init() {
	this->bindMenus();
	this->bindTitle();
	this->bindList();
	this->_init(this->titleView.str(), "View menus", true);
	this->action(this->getCurrIndex());
}