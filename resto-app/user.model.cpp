#include "user.model.h"

int UserModel::getId() {
	return this->id;
}

void UserModel::setId(int id) {
	this->id = id;
}

string UserModel::getUsername() {
	return this->username;
}

void UserModel::setUsername(string username) {
	this->username = username;
}

string UserModel::getName() {
	return this->name;
}

void UserModel::setName(string name) {
	this->name = name;
}

string UserModel::getPassword() {
	return this->password;
}

void UserModel::setPassword(string password) {
	this->password = password;
}

int UserModel::getRole() {
	return this->role;
}

void UserModel::setRole(int role) {
	this->role = role;
}