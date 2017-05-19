#include "transaction.model.h"

int TransactionModel::getId() {
	return this->id;
}

void TransactionModel::setId(int id) {
	this->id = id;
}

string TransactionModel::getStatus() {
	return this->status;
}

void TransactionModel::setStatus(string status) {
	this->status = status;
}