#include "user-add.admin.component.h"

void UserAddAdminComponent::doSubmit(string username, string name, string password, int role) {
	UserModel user;
	user.setUsername(username);
	user.setName(name);
	user.setPassword(password);
	user.setRole(role);

	bool save = this->userProvider.add(user);

	if (save) {
		this->success();
	}
	else {
		this->error();
	}

	UserAdminComponent userAdminComponent;
	userAdminComponent.init();
}

void UserAddAdminComponent::success() {
	this->componentHoldMessage("Success add user!");
}

void UserAddAdminComponent::error() {
	this->componentErrorMessage("Error add user!");
}

void UserAddAdminComponent::init() {
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

	username = StreamHelper::stringValidator(username, "Input Username: ", usernameRules);
	name = StreamHelper::stringValidator(name, "Input Name: ", nameRules);
	password = StreamHelper::stringValidator(password, "Input Password: ", passwordRules);
	role = roleSelect.init(roles.roleLabels, "Choose User Role: ");

	this->doSubmit(username, name, password, role + 1);

	StreamHelper::hold();
}