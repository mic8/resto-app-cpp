#include "transaction.admin.component.h"

void TransactionAdminComponent::bindList() {
	this->list.push_back("All Transactions");
}

void TransactionAdminComponent::bindTitle(string title) {
	this->setTitle(title);
}

void TransactionAdminComponent::viewTransactions() {
	TransactionViewAdminComponent transactionViewAdmin;
	transactionViewAdmin.init();
}

void TransactionAdminComponent::action(int currIndex) {
	StreamHelper::cls();

	switch (currIndex) {
	case 0:
		this->viewTransactions();
		break;
	}
}

void TransactionAdminComponent::back() {
	VendorAdminComponent vendorAdminComponent;
	vendorAdminComponent.init();
}

void TransactionAdminComponent::init() {
	this->bindList();
	this->bindTitle("Choose your action to manage transaction: ");

	StreamHelper::cls();
	this->_init(true);

	if (this->isBack) {
		this->back();
	}
	else {
		this->action(this->getCurrIndex());
	}
}