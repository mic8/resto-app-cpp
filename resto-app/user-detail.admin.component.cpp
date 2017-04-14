#include "user-detail.admin.component.h"

string UserDetailAdminComponent::header() {
	return "--------------------------------------------------------------------------------------------------";
}

void UserDetailAdminComponent::bindUser(UserModel user) {
	this->user = user;
}

void UserDetailAdminComponent::bindTitle() {
	stringstream title;
	title << this->header() << endl
		<< "| #ID | \t\tUsername\t\t | \t\tName\t\t | \tRole\t |" << endl
		<< this->header() << endl
		<< "| " << setw(3) << this->user.getId() << " | "
		<< setiosflags(ios::left) << setw(40) << this->user.getUsername() << " | "
		<< setw(29) << this->user.getName() << " | "
		<< setiosflags(ios::right) << setw(13) << this->roleModel.roleLabels[this->user.getRole() - 1]
		<< " | " << endl
		<< this->header();
	title.unsetf(StreamHelper::UNSET);
	title << endl << "Choose your action: " << endl;

	this->setTitle(title.str());
}

void UserDetailAdminComponent::bindList() {
	this->list.erase(this->list.begin(), this->list.end());
	this->addList("Delete");
	this->addList("Edit");
}

void UserDetailAdminComponent::doDelete() {
	bool removed = this->userProvider.remove(this->user);

	if (removed) {
		this->componentHoldMessage("Success delete user with #ID: " + this->user.getId());
		UserViewAdminComponent userViewAdminComponent;
		userViewAdminComponent.init();
	}
	else {
		this->componentErrorMessage("Error delete user maybe is your account to be deleted or something wrong");
		this->init(this->user);
	}
}

void UserDetailAdminComponent::doEdit() {
	UserEditAdminComponent userEditAdminComponent;
	userEditAdminComponent.init(this->user);
}

void UserDetailAdminComponent::action(int currIndex) {
	if (this->isBack) {
		UserViewAdminComponent userViewAdminComponent;
		userViewAdminComponent.init();
	}
	else if (this->isExit) {
		switch (currIndex) {
		case 0 :
			this->doDelete();
			break;
		case 1 :
			this->doEdit();
			break;
		}
	}
}

void UserDetailAdminComponent::init(UserModel user) {
	this->bindUser(user);
	this->bindTitle();
	this->bindList();

	this->_init(true);

	this->action(this->getCurrIndex());
}