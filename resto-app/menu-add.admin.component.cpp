#include "menu-add.admin.component.h"

void MenuAddAdminComponent::doSubmit(string name, double price, int qty) {
	MenuModel menu;
	menu.setName(name);
	menu.setPrice(price);
	menu.setQty(qty);

	bool save = this->menuProvider.add(menu);

	if (save) {
		this->success();
	}
	else {
		this->error();
	}

	MenuAdminComponent menuAdminComponent;
	menuAdminComponent.init();
}

void MenuAddAdminComponent::success() {
	this->componentHoldMessage("Success add menu!");
}

void MenuAddAdminComponent::error() {
	this->componentErrorMessage("Error add menu!");
}

void MenuAddAdminComponent::init() {
	StreamHelper::cls();

	string name;
	vector<string>nameRules;
	nameRules.push_back("required");
	nameRules.push_back("min:6");
	nameRules.push_back("max:40");

	name = StreamHelper::stringValidator(name, "Input Name: ", nameRules);

	double price;
	int qty;

	do {
		StreamHelper::cls();
		cout << "Input Price: ";
		cin >> price; cin.sync(); cin.clear();
	} while (price <= 0);

	do {
		StreamHelper::cls();
		cout << "Input Qty[1-100]: ";
		cin >> qty; cin.sync(); cin.clear();
	} while (qty <= 0 || qty > 100);

	this->doSubmit(name, price, qty);

	StreamHelper::hold();
}