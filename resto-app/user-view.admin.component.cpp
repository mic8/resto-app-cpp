#include "user-view.admin.component.h"

void UserViewAdminComponent::bindUsers() {
	this->users = this->userProvider.all();
}

void UserViewAdminComponent::bindTitle() {
	this->titleView << this->header() << endl;
	this->titleView << "  | #ID |   \t\tUsername\t\t   |   \t\tName\t\t   |   \tRole\t   |" << endl;
	this->titleView << this->header();
}

void UserViewAdminComponent::bindList() {
	int i;
	for (i = 0; i < this->users.size(); i++) {
		stringstream list;
		list << "| " << setw(3) << this->users[i].getId() << " | "
			<< setiosflags(ios::left) << setw(40) << this->users[i].getUsername() << " | "
			<< setw(29) << this->users[i].getName() << " | "
			<< setiosflags(ios::right) << setw(13) << this->roleModel.roleLabels[this->users[i].getRole() - 1]
			<< " | " << endl;
		list << this->header();
		list.unsetf(StreamHelper::UNSET);

		this->addList(list.str());
	}
}

string UserViewAdminComponent::header() {
	return "  --------------------------------------------------------------------------------------------------";
}

void UserViewAdminComponent::action(int currIndex) {
	if (this->isBack) {
		UserAdminComponent userAdminComponent;
		userAdminComponent.init();
	}
	else if (this->isExit) {
		this->user = this->users[this->getCurrIndex()];
		UserDetailAdminComponent userDetailAdminComponent;
		userDetailAdminComponent.init(this->user);
	}
}

void UserViewAdminComponent::init() {
	this->bindUsers();
	this->bindTitle();
	this->bindList();
	this->_init(this->titleView.str(), "View users", true);
	this->action(this->getCurrIndex());
}