#include "transaction-view.admin.component.h"

void TransactionViewAdminComponent::bindTransactions() {
	this->transactions = this->transactionProvider.all();
}

void TransactionViewAdminComponent::bindTitle() {
	this->titleView.clear();
	this->titleView.str(string());
	this->titleView << this->header() << endl;
	this->titleView << "  | #ID |   \tStatus\t   " << endl;
	this->titleView << this->header();
}

void TransactionViewAdminComponent::bindList() {
	int i;
	for (i = 0; i < this->transactions.size(); i++) {
		stringstream list;
		list << "| " << setw(3) << this->transactions[i].getId() << " | "
			<< setiosflags(ios::left) << setw(20) << this->transactions[i].getStatus() << endl;
		list << this->header();
		list.unsetf(StreamHelper::UNSET);

		this->addList(list.str());
	}
}

string TransactionViewAdminComponent::header() {
	return "  -----------------------------------------------------";
}

void TransactionViewAdminComponent::action(int currIndex) {
	if (this->isBack) {
		TransactionAdminComponent transactionAdminComponent;
		transactionAdminComponent.init();
	}
	else if (this->isExit) {
		this->transaction = this->transactions[this->getCurrIndex()];
		TransactionDetailAdminComponent transactionDetailAdminComponent;
		transactionDetailAdminComponent.init(this->transaction);
	}
}

void TransactionViewAdminComponent::init() {
	StreamHelper::cls();
	this->bindTransactions();
	this->bindTitle();
	this->bindList();
	this->_init(this->titleView.str(), "View Transactions", true);
	this->action(this->getCurrIndex());
}

void TransactionViewAdminComponent::doUpdateTransaction() {
	TransactionModel find = this->transactions[this->getCurrIndex()];
	string status = find.getStatus();
	status = status == "ORDER" ? "DONE" : "ORDER";
	find.setStatus(status);

	this->transactionProvider.update(find);
}