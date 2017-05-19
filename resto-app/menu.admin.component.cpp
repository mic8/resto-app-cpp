#include "menu.admin.component.h"

void MenuAdminComponent::bindList() {
	this->list.push_back("Add Menu");
	this->list.push_back("View Menus");
}

void MenuAdminComponent::bindTitle(string title) {
	this->setTitle(title);
}

void MenuAdminComponent::addMenu() {
	MenuAddAdminComponent menuAdd;
	menuAdd.init();
}

void MenuAdminComponent::viewMenus() {
	MenuViewAdminComponent menuView;
	menuView.init();
}

void MenuAdminComponent::action(int currIndex) {
	StreamHelper::cls();

	switch (currIndex) {
	case 0:
		this->addMenu();
		break;
	case 1:
		this->viewMenus();
		break;
	}
}

void MenuAdminComponent::back() {
	VendorAdminComponent vendorAdminComponent;
	vendorAdminComponent.init();
}

void MenuAdminComponent::init() {
	this->bindList();
	this->bindTitle("Choose your action to manage food / beverages: ");

	StreamHelper::cls();
	this->_init(true);

	if (this->isBack) {
		this->back();
	}
	else {
		this->action(this->getCurrIndex());
	}
}