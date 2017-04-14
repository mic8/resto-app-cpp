#include "login.component.h"

void LoginComponent::doLogin(UserModel user, string password) {
	if (user.getId()) {
		if (user.getPassword() == password) {
			UserLoggedModel::USER = user.getId();
			this->success("Welcome " + user.getName());
		}
		else {
			this->error("Invalid password!");
		}
	}
	else {
		this->error("User not found!");
	}
}

void LoginComponent::doLoggedAsAdmin() {
	VendorAdminComponent vendorAdminComponent;
	vendorAdminComponent.init();
}

void LoginComponent::success(string message) {
	UserModel user = this->userProvider.findById(UserLoggedModel::USER);
	switch (user.getRole()) {
	case RoleModel::ADMIN:
		this->doLoggedAsAdmin();
		break;
	case RoleModel::WAITER:
		break;
	case RoleModel::CUSTOMER:
		break;
	}

	this->componentHoldMessage(message);
}

void LoginComponent::error(string message) {
	this->componentErrorMessage(message);
	this->init();
}

void LoginComponent::init() {
	StreamHelper::cls();

	string username;
	vector<string>usernameRules;
	usernameRules.push_back("required");
	usernameRules.push_back("min:4");
	usernameRules.push_back("max:30");

	string password;
	vector<string>passwordRules;
	passwordRules.push_back("required");
	passwordRules.push_back("min:4");
	passwordRules.push_back("max:30");

	username = StreamHelper::stringValidator(username, "Input Your Username: ", usernameRules);
	password = StreamHelper::stringValidator(password, "Input Your Password: ", passwordRules);

	UserModel user = this->userProvider.findByUsername(username);
	this->doLogin(user, password);

	StreamHelper::hold();
}