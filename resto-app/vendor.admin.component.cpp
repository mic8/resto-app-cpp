#include "vendor.admin.component.h"

void VendorAdminComponent::bindLoggedUser() {
	this->userLogged = this->userProvider.findById(UserLoggedModel::USER);
}

void VendorAdminComponent::bindList() {
	this->list.push_back("Manage User");
	this->list.push_back("Logout");
}

void VendorAdminComponent::bindTitle(string title) {
	this->setTitle(title);
}

void VendorAdminComponent::doManageUser() {
	UserAdminComponent userAdminComponent;
	userAdminComponent.init();
}

void VendorAdminComponent::doLogout() {
	UserLoggedModel::USER = 0;

	AuthComponent authComponent;
	authComponent.init();
}

void VendorAdminComponent::action(int currIndex) {
	switch (currIndex) {
	case 0:
		this->doManageUser();
		break;
	case 1:
		this->doLogout();
		break;
	}
}

void VendorAdminComponent::init() {
	this->bindLoggedUser();
	this->bindList();
	this->bindTitle("Welcome " + this->userLogged.getName() + ", choose your action: ");

	StreamHelper::cls();
	this->_init(false);

	this->action(this->getCurrIndex());
}