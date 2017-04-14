#include "user-edit.admin.component.h"

void UserEditAdminComponent::doSubmit(string username, string name, string password, int role) {
	UserModel user;
	user.setUsername(username);
	user.setName(name);
	user.setPassword(password);
	user.setRole(role);

	bool updated = this->userProvider.update(user);

	if (updated) {
		this->success();
	}
	else {
		this->error();
	}
}

void UserEditAdminComponent::success() {
	this->componentHoldMessage("Success update user");
	UserViewAdminComponent userViewAdminComponent;
	userViewAdminComponent.init();
}

void UserEditAdminComponent::error() {
	this->componentErrorMessage("Error update user");
	UserViewAdminComponent userViewAdminComponent;
	userViewAdminComponent.init();
}

void UserEditAdminComponent::init(UserModel user) {
	StreamHelper::cls();

	string username;
	vector<string>usernameRules;
	usernameRules.push_back("required");
	usernameRules.push_back("min:4");
	usernameRules.push_back("max:30");

	string name;
	vector<string>nameRules;
	nameRules.push_back("required");
	nameRules.push_back("min:6");
	nameRules.push_back("max:40");

	string password;
	vector<string>passwordRules;
	passwordRules.push_back("required");
	passwordRules.push_back("min:4");
	passwordRules.push_back("max:30");

	int role = NULL;
	SelectComponent roleSelect;
	RoleModel roles;

	username = StreamHelper::stringValidator(username, "Change Username(" + user.getUsername() + "): ", usernameRules);
	name = StreamHelper::stringValidator(name, "Change Name(" + user.getName() + "): ", nameRules);
	password = StreamHelper::stringValidator(password, "Change Password: ", passwordRules);
	role = roleSelect.init(roles.roleLabels, "Choose User Role(" + roles.roleLabels[user.getRole() - 1] + "): ");

	this->doSubmit(username, name, password, role + 1);

	StreamHelper::hold();
}