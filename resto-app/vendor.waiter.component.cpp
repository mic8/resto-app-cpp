#include "vendor.admin.component.h"

void VendorWaiterComponent::bindLoggedUser() {
	this->userLogged = this->userProvider.findById(UserLoggedModel::USER);
}

void VendorWaiterComponent::bindList() {
	this->list.push_back("New Order + ");
	this->list.push_back("Logout");
}

void VendorWaiterComponent::bindTitle(string title) {
	this->setTitle(title);
}

void VendorWaiterComponent::doOrder() {
	MenuWaiterComponent menuWaiterComponent;
	menuWaiterComponent.init();
}

void VendorWaiterComponent::doLogout() {
	UserLoggedModel::USER = 0;

	AuthComponent authComponent;
	authComponent.init();
}

void VendorWaiterComponent::action(int currIndex) {
	switch (currIndex) {
	case 0:
		this->doOrder();
		break;
	case 1:
		this->doLogout();
		break;
	}
}

void VendorWaiterComponent::init() {
	this->bindLoggedUser();
	this->bindList();
	this->bindTitle("Welcome " + this->userLogged.getName() + ", choose your action: ");

	StreamHelper::cls();
	this->_init(false);

	this->action(this->getCurrIndex());
}