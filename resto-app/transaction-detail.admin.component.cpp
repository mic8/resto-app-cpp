#include "transaction-detail.admin.component.h"

void TransactionDetailAdminComponent::bindTransactionDetails(TransactionModel transaction) {
	vector<TransactionDetailModel> all = this->transactionDetailProvider.all();
	int i;
	for (i = 0; i < all.size(); i++) {
		if (all[i].getTransaction() == transaction.getId()) {
			this->transactions.push_back(all[i]);
		}
	}
}

void TransactionDetailAdminComponent::bindTitle() {
	this->titleView << this->header() << endl;
	this->titleView << "  | #ID |   \t\tTransaction ID\t\t   |   \t\tMenu ID\t\t   |   \tQuantity   |" << endl;
	this->titleView << this->header();
}

void TransactionDetailAdminComponent::bindList() {
	int i;
	for (i = 0; i < this->transactions.size(); i++) {
		stringstream list;
		list << "| " << setw(3) << this->transactions[i].getId() << " | "
			<< setiosflags(ios::right) << setw(40) << this->transactions[i].getTransaction() << " | "
			<< setw(29) << this->transactions[i].getMenu() << " | "
			<< setiosflags(ios::right) << setw(13) << this->transactions[i].getQty()
			<< " | " << endl;
		list << this->header();
		list.unsetf(StreamHelper::UNSET);

		this->addList(list.str());
	}
}

string TransactionDetailAdminComponent::header() {
	return "  --------------------------------------------------------------------------------------------------";
}

void TransactionDetailAdminComponent::action(int currIndex) {
	if (this->isBack) {
		TransactionViewAdminComponent transactionViewAdminComponent;
		transactionViewAdminComponent.init();
	}
}

void TransactionDetailAdminComponent::init(TransactionModel transaction) {
	this->bindTransactionDetails(transaction);
	this->bindTitle();
	this->bindList();
	this->_init(this->titleView.str(), "Transaction details", true);
	this->action(this->getCurrIndex());
}