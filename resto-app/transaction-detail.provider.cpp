#include "transaction-detail.provider.h"

TransactionDetailProvider::TransactionDetailProvider() {
	this->setPath("transaction-detail.csv");
	this->bindTransactions();
	this->bindTransaction();
}

void TransactionDetailProvider::bindTransactions() {
	int i;
	for (i = 0; i < this->files().size(); i++) {
		TransactionDetailModel transactionDetailModel;
		transactionDetailModel.setId(stoi(this->files()[i][0]));
		transactionDetailModel.setTransaction(stoi(this->files()[i][1]));
		transactionDetailModel.setMenu(stoi(this->files()[i][2]));
		transactionDetailModel.setQty(stoi(this->files()[i][3]));

		this->transactions.push_back(transactionDetailModel);
	}
}

void TransactionDetailProvider::bindTransaction() {
	this->transaction.setId(0);
	this->transaction.setTransaction(0);
	this->transaction.setMenu(0);
	this->transaction.setQty(0);
}

void TransactionDetailProvider::setResult() {
	int i;
	for (i = 0; i < this->transactions.size(); i++) {
		this->result.push_back(
			to_string(this->transactions[i].getId()) + this->delimiter + 
			to_string(this->transactions[i].getTransaction()) + this->delimiter +
			to_string(this->transactions[i].getMenu()) + this->delimiter +
			to_string(this->transactions[i].getQty())
			);
	}
}

vector<TransactionDetailModel> TransactionDetailProvider::all() {
	return this->transactions;
}

bool TransactionDetailProvider::add(TransactionDetailModel transactionDetail) {
	TransactionDetailModel last = this->last();
	transactionDetail.setId(last.getId() + 1);

	try {
		this->transactions.push_back(transactionDetail);
		this->setResult();
		this->save();
		return true;
	}
	catch (exception e) {
		return false;
	}
}

bool TransactionDetailProvider::remove(TransactionDetailModel transactionDetail) {
	try {
		this->transactions.erase(this->transactions.begin() + this->getIndex(transactionDetail.getId()));
		this->setResult();
		this->save();
		return true;
	}
	catch (exception e) {
		return false;
	}
}

bool TransactionDetailProvider::update(TransactionDetailModel transactionDetail) {
	try {
		int index = this->getIndex(transactionDetail.getId());
		this->transactions[index].setTransaction(transactionDetail.getTransaction());
		this->transactions[index].setMenu(transactionDetail.getMenu());
		this->transactions[index].setQty(transactionDetail.getQty());

		this->setResult();
		this->save();

		return true;
	}
	catch (exception e) {
		return false;
	}
}

int TransactionDetailProvider::getIndex(int id) {
	int i;
	bool hasFounded = false;
	for (i = 0; i < this->transactions.size(); i++) {
		if (this->transactions[i].getId() == id) {
			hasFounded = true;
			break;
		}
	}

	if (hasFounded) {
		return i;
	}
	else {
		return NULL;
	}
}

TransactionDetailModel TransactionDetailProvider::findById(int id) {
	int i;
	bool hasFounded = false;
	for (i = 0; i < this->transactions.size(); i++) {
		if (this->transactions[i].getId() == id) {
			hasFounded = true;
			break;
		}
	}

	if (hasFounded) {
		return this->transactions[i];
	}
	else {
		return this->transaction;
	}
}

TransactionDetailModel TransactionDetailProvider::last() {
	if (this->transactions.size() == 0) {
		return this->transaction;
	}
	else {
		return this->transactions[this->transactions.size() - 1];
	}
}

bool TransactionDetailProvider::hasById(int id) {
	TransactionDetailModel transaction;
	transaction = this->findById(id);

	if (transaction.getId()) {
		return true;
	}

	return false;
}