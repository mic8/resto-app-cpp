#include "user.provider.h"

UserProvider::UserProvider() {
	this->setPath("user.csv");
	this->bindUsers();
	this->bindUser();
}

void UserProvider::bindUsers() {
	int i;
	for (i = 0; i < this->files().size(); i++) {
		UserModel userModel;
		userModel.setId(stoi(this->files()[i][0]));
		userModel.setUsername(this->files()[i][1]);
		userModel.setName(this->files()[i][2]);
		userModel.setPassword(this->files()[i][3]);
		userModel.setRole(stoi(this->files()[i][4]));

		this->users.push_back(userModel);
	}
}

void UserProvider::bindUser() {
	this->user.setId(0);
	this->user.setUsername("");
	this->user.setName("");
	this->user.setPassword("");
	this->user.setRole(-1);
}

void UserProvider::setResult() {
	int i;
	for (i = 0; i < this->users.size(); i++) {
		this->result.push_back(
			to_string(this->users[i].getId()) + this->delimiter + this->users[i].getUsername() + this->delimiter +
			this->users[i].getName() + this->delimiter + this->users[i].getPassword() + this->delimiter +
			to_string(this->users[i].getRole())
		);
	}
}

vector<UserModel> UserProvider::all() {
	return this->users;
}

bool UserProvider::add(UserModel user) {
	UserModel last = this->last();
	user.setId(last.getId() + 1);

	try {
		if (!this->hasByUsername(user.getUsername())) {
			this->users.push_back(user);
			this->setResult();
			this->save();
			return true;
		}
		else {
			return false;
		}
	}
	catch (exception e) {
		return false;
	}
}

bool UserProvider::remove(UserModel user) {
	try {
		if (UserLoggedModel::USER == user.getId()) {
			return false;
		}
		else {
			this->users.erase(this->users.begin() + this->getIndex(user.getId()));
			this->setResult();
			this->save();
			return true;
		}
	}
	catch (exception e) {
		return false;
	}
}

bool UserProvider::update(UserModel user) {
	try {
		int index = this->getIndex(user.getId());
		this->users[index].setUsername(user.getUsername());
		this->users[index].setName(user.getName());
		this->users[index].setPassword(user.getPassword());
		this->users[index].setRole(user.getRole());

		this->setResult();
		this->save();

		return true;
	}
	catch (exception e) {
		return false;
	}
}

int UserProvider::getIndex(int id) {
	int i;
	bool hasFounded = false;
	for (i = 0; i < this->users.size(); i++) {
		if (this->users[i].getId() == id) {
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

UserModel UserProvider::findById(int id) {
	int i;
	bool hasFounded = false;
	for (i = 0; i < this->users.size(); i++) {
		if (this->users[i].getId() == id) {
			hasFounded = true;
			break;
		}
	}

	if (hasFounded) {
		return this->users[i];
	}
	else {
		return this->user;
	}
}

UserModel UserProvider::findByUsername(string username) {
	int i;
	bool hasFounded = false;
	for (i = 0; i < this->users.size(); i++) {
		if (this->users[i].getUsername() == username) {
			hasFounded = true;
			break;
		}
	}
	if (hasFounded) {
		return this->users[i];
	}
	else {
		return this->user;
	}
}

UserModel UserProvider::last() {
	if (this->users.size() == 0) {
		return this->user;
	}
	else {
		return this->users[this->users.size() - 1];
	}
}

bool UserProvider::hasById(int id) {
	UserModel user;
	user = this->findById(id);

	if (user.getId()) {
		return true;
	}

	return false;
}

bool UserProvider::hasByUsername(string username) {
	UserModel user;
	user = this->findByUsername(username);

	if (user.getId()) {
		return true;
	}

	return false;
}