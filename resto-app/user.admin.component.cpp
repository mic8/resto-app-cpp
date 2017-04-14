#include "user.admin.component.h"

void UserAdminComponent::bindList() {
	this->list.push_back("Add User");
	this->list.push_back("View Users");
}

void UserAdminComponent::bindTitle(string title) {
	this->setTitle(title);
}

void UserAdminComponent::addUser() {
	UserAddAdminComponent userAdd;
	userAdd.init();
}

void UserAdminComponent::viewUsers() {
	UserViewAdminComponent userView;
	userView.init();
}

void UserAdminComponent::action(int currIndex) {
	StreamHelper::cls();

	switch (currIndex) {
	case 0 :
		this->addUser();
		break;
	case 1 :
		this->viewUsers();
		break;
	case 2 :
		//update user
		break;
	case 3 :
		//delete user
		break;
	}
}

void UserAdminComponent::back() {
	VendorAdminComponent vendorAdminComponent;
	vendorAdminComponent.init();
}

void UserAdminComponent::init() {
	this->bindList();
	this->bindTitle("Choose your action to manage user: ");

	StreamHelper::cls();
	this->_init(true);

	if (this->isBack) {
		this->back();
	}
	else {
		this->action(this->getCurrIndex());
	}
}