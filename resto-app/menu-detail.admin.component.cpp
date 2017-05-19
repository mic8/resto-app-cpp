#include "menu-detail.admin.component.h"

string MenuDetailAdminComponent::header() {
	return "--------------------------------------------------------------------------------------------------";
}

void MenuDetailAdminComponent::bindMenu(MenuModel menu) {
	this->menu = menu;
}

void MenuDetailAdminComponent::bindTitle() {
	stringstream title;
	title << this->header() << endl
		<< "| #ID |   \t\tMenu Name\t\t |   \t\tPrice\t\t |   \tQuantity |" << endl
		<< this->header() << endl
		<< "| " << setw(3) << this->menu.getId() << " | "
		<< setiosflags(ios::left) << setw(40) << this->menu.getName() << " | "
		<< setw(29) << this->menu.getPrice() << " | "
		<< setiosflags(ios::right) << setw(13) << this->menu.getQty()
		<< " | " << endl
		<< this->header();
	title.unsetf(StreamHelper::UNSET);
	title << endl << "Choose your action: " << endl;

	this->setTitle(title.str());
}

void MenuDetailAdminComponent::bindList() {
	this->list.erase(this->list.begin(), this->list.end());
	this->addList("Delete");
	this->addList("Edit");
}

void MenuDetailAdminComponent::doDelete() {
	bool removed = this->menuProvider.remove(this->menu);

	if (removed) {
		this->componentHoldMessage("Success delete menu with #ID: " + this->menu.getId());
		MenuViewAdminComponent menuViewAdminComponent;
		menuViewAdminComponent.init();
	}
	else {
		this->componentErrorMessage("Error delete menu something wrong");
		this->init(this->menu);
	}
}

void MenuDetailAdminComponent::doEdit() {
	MenuEditAdminComponent MenuEditAdminComponent;
	MenuEditAdminComponent.init(this->menu);
}

void MenuDetailAdminComponent::action(int currIndex) {
	if (this->isBack) {
		MenuViewAdminComponent menuViewAdminComponent;
		menuViewAdminComponent.init();
	}
	else if (this->isExit) {
		switch (currIndex) {
		case 0:
			this->doDelete();
			break;
		case 1:
			this->doEdit();
			break;
		}
	}
}

void MenuDetailAdminComponent::init(MenuModel menu) {
	this->bindMenu(menu);
	this->bindTitle();
	this->bindList();

	this->_init(true);

	this->action(this->getCurrIndex());
}