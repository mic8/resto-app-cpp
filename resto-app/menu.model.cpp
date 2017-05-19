#include "menu.model.h"

int MenuModel::getId() {
	return this->id;
}

void MenuModel::setId(int id) {
	this->id = id;
}

string MenuModel::getName() {
	return this->name;
}

void MenuModel::setName(string name) {
	this->name = name;
}

double MenuModel::getPrice() {
	return this->price;
}

void MenuModel::setPrice(double price) {
	this->price = price;
}

int MenuModel::getQty() {
	return this->qty;
}

void MenuModel::setQty(int qty) {
	this->qty = qty;
}