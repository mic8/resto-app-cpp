#include "transaction-detail.model.h"

int TransactionDetailModel::getId() {
	return this->id;
}

void TransactionDetailModel::setId(int id) {
	this->id = id;
}

int TransactionDetailModel::getTransaction() {
	return this->transaction;
}

void TransactionDetailModel::setTransaction(int transaction) {
	this->transaction = transaction;
}

int TransactionDetailModel::getMenu() {
	return this->menu;
}

void TransactionDetailModel::setMenu(int menu) {
	this->menu = menu;
}

int TransactionDetailModel::getQty() {
	return this->qty;
}

void TransactionDetailModel::setQty(int qty) {
	this->qty = qty;
}