#include "menu-edit.admin.component.h"

void MenuEditAdminComponent::doSubmit(string name, double price, int qty) {
	MenuModel menu;
	menu.setName(name);
	menu.setPrice(price);
	menu.setQty(qty);

	bool updated = this->menuProvider.update(menu);

	if (updated) {
		this->success();
	}
	else {
		this->error();
	}
}

void MenuEditAdminComponent::success() {
	this->componentHoldMessage("Success update user");
	MenuViewAdminComponent menuViewAdminComponent;
	menuViewAdminComponent.init();
}

void MenuEditAdminComponent::error() {
	this->componentErrorMessage("Error update user");
	MenuViewAdminComponent menuViewAdminComponent;
	menuViewAdminComponent.init();
}

void MenuEditAdminComponent::init(MenuModel menu) {
	StreamHelper::cls();

	string name;
	vector<string>nameRules;
	nameRules.push_back("required");
	nameRules.push_back("min:6");
	nameRules.push_back("max:40");

	name = StreamHelper::stringValidator(name, "Change Name(" + menu.getName() + "): ", nameRules);

	double price;
	int qty;

	do {
		StreamHelper::cls();
		cout << "Change Price(" << menu.getPrice() << "): ";
		cin >> price; cin.sync(); cin.clear();
	} while (price <= 0);

	do {
		StreamHelper::cls();
		cout << "Change Qty(" << menu.getQty() << ")[1-100]: ";
		cin >> qty; cin.sync(); cin.clear();
	} while (qty <= 0 || qty > 100);

	this->doSubmit(name, price, qty);

	StreamHelper::hold();
}