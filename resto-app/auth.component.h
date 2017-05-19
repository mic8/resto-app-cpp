#pragma once

#include "menu.component.h"
#include "login.component.h"
#include "register.component.h"

class AuthComponent: MenuComponent {

private:
	void bindList();

	void bindTitle(string title);

	void action(int currIndex);

public:
	void doLogin();
	
	void doRegister();

	void doExit();

	void init();

};