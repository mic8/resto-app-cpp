#include "transaction.provider.h"

TransactionProvider::TransactionProvider() {
	this->setPath("transaction.csv");
	this->bindTransactions();
	this->bindTransaction();
}

void TransactionProvider::bindTransactions() {
	int i;
	for (i = 0; i < this->files().size(); i++) {
		TransactionModel transactionModel;
		transactionModel.setId(stoi(this->files()[i][0]));
		transactionModel.setStatus(this->files()[i][1]);

		this->transactions.push_back(transactionModel);
	}
}

void TransactionProvider::bindTransaction() {
	this->transaction.setId(0);
}

void TransactionProvider::setResult() {
	int i;
	for (i = 0; i < this->transactions.size(); i++) {
		this->result.push_back(
			to_string(this->transactions[i].getId()) + this->delimiter + 
			this->transactions[i].getStatus()
		);
	}
}

vector<TransactionModel> TransactionProvider::all() {
	return this->transactions;
}

int TransactionProvider::add(TransactionModel transaction) {
	TransactionModel last = this->last();
	transaction.setId(last.getId() + 1);

	try {
		this->transactions.push_back(transaction);
		this->setResult();
		this->save();
		return transaction.getId();
	}
	catch (exception e) {
		return 0;
	}
}

bool TransactionProvider::remove(TransactionModel transaction) {
	try {
		this->transactions.erase(this->transactions.begin() + this->getIndex(transaction.getId()));
		this->setResult();
		this->save();
		return true;
	}
	catch (exception e) {
		return false;
	}
}

bool TransactionProvider::update(TransactionModel transaction) {
	try {
		int index = this->getIndex(transaction.getId());
		this->transactions[index].setStatus(transaction.getStatus());

		this->setResult();
		this->save();

		return true;
	}
	catch (exception e) {
		return false;
	}
}

int TransactionProvider::getIndex(int id) {
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

TransactionModel TransactionProvider::findById(int id) {
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

TransactionModel TransactionProvider::last() {
	if (this->transactions.size() == 0) {
		return this->transaction;
	}
	else {
		return this->transactions[this->transactions.size() - 1];
	}
}

bool TransactionProvider::hasById(int id) {
	TransactionModel transaction;
	transaction = this->findById(id);

	if (transaction.getId()) {
		return true;
	}

	return false;
}