#include "auth.component.h"

void AuthComponent::bindList() {
	this->addList("Sign In / Masuk");
	this->addList("Register / Daftar Akun");
}

void AuthComponent::bindTitle(string title) {
	this->setTitle(title);
}

void AuthComponent::action(int currIndex) {
	switch (currIndex) {
	case 0 :
		this->doLogin();
		break;
	case 1 :
		this->doRegister();
		break;
	}
}

void AuthComponent::doLogin() {
	LoginComponent loginComponent;
	loginComponent.init();
}

void AuthComponent::doRegister() {
	RegisterComponent registerComponent;
	registerComponent.init();
}

void AuthComponent::init() {
	this->bindList();
	this->bindTitle("Choose Your Action: ");

	StreamHelper::cls();

	cout << setw(40) << "Resto App v1.0" << endl;
	cout << setw(47) << "Welcome to Square Restaurant" << endl;
	cout.unsetf(StreamHelper::UNSET);

	this->componentHoldMessage("This is an application to manage a Restaurant!");

	this->_init(false);

	this->action(this->getCurrIndex());
}