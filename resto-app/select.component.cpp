#include "select.component.h"

void SelectComponent::bindList(vector<string> list) {
	int i;

	for (i = 0; i < list.size(); i++) {
		this->addList(list[i]);
	}
}

void SelectComponent::bindTitle(string title) {
	this->setTitle(title);
}

int SelectComponent::init(vector<string> list, string title) {
	this->bindList(list);
	this->bindTitle(title);
	this->_init(false);

	return this->getCurrIndex();
}