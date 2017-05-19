#include "menu.waiter.component.h"

void MenuWaiterComponent::bindMenus() {
	this->menus.clear();
	this->menus = this->menuProvider.all();
}

void MenuWaiterComponent::bindTitle() {
	this->titleView.clear();
	this->titleView.str(string());
	this->titleView << this->header() << endl;
	this->titleView << "  | #ID |   \t\tMenu Name\t\t   |   \t\tPrice\t\t   |   \tQuantity   |" << endl;
	this->titleView << this->header();
}

void MenuWaiterComponent::bindList() {
	int i;
	this->resetList();
	for (i = 0; i < this->menus.size(); i++) {
		stringstream list;
		list << "| " << setw(3) << this->menus[i].getId() << " | "
			<< setiosflags(ios::left) << setw(40) << this->menus[i].getName() << " | "
			<< setw(29) << this->menus[i].getPrice() << " | "
			<< setiosflags(ios::right) << setw(13) << this->menus[i].getQty()
			<< " | " << endl;
		list << this->header();
		list.unsetf(StreamHelper::UNSET);

		this->addList(list.str());
	}
}

string MenuWaiterComponent::header() {
	return "  --------------------------------------------------------------------------------------------------";
}

void MenuWaiterComponent::action(int currIndex) {
	if (this->isBack) {
		VendorWaiterComponent vendorWaiterComponent;
		vendorWaiterComponent.init();
	}
	else if (this->isExit) {
		this->menu = this->menus[this->getCurrIndex()];
		this->doChooseMenu();
	}
}

void MenuWaiterComponent::init() {
	this->doCreateTransaction();
	this->reset();
}

void MenuWaiterComponent::reset() {
	StreamHelper::cls();
	this->bindMenus();
	this->bindTitle();
	this->bindList();
	this->_init(this->titleView.str(), "View menus", true);
	this->action(this->getCurrIndex());
}

void MenuWaiterComponent::doCreateTransaction() {
	TransactionModel transactionModel;
	transactionModel.setStatus("ORDER");

	this->transactionId = this->transactionProvider.add(transactionModel);
}

void MenuWaiterComponent::doChooseMenu() {
	StreamHelper::cls();

	TransactionDetailModel transactionDetailModel;
	transactionDetailModel.setMenu(this->menu.getId());
	transactionDetailModel.setTransaction(this->transactionId);

	int qty;
	do {
		StreamHelper::cls();
		cout << "Input Qty[1-" << this->menu.getQty() << "]: ";
		cin >> qty; cin.sync(); cin.clear();
	} while (qty < 1 || qty > this->menu.getQty());

	transactionDetailModel.setQty(qty);
	this->menuProvider.updateQty(this->menu.getId(), this->menu.getQty() - qty);

	this->transactionDetailProvider.add(transactionDetailModel);
	this->reset();
}