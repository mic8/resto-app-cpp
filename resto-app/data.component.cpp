#include "data.component.h"

void DataComponent::moveUp() {
	if (this->currIndex > 0) this->currIndex--;
}

void DataComponent::moveDown() {
	if (this->currIndex < this->maxIndex) this->currIndex++;
}

void DataComponent::addList(string label) {
	this->list.push_back(label);
}

void DataComponent::setTitle(string title) {
	this->title = title;
}

void DataComponent::setFooter(string footer) {
	this->footer = footer;
}

void DataComponent::bindIndex() {
	this->currIndex = 0;
	if (this->list.size() != 0) {
		this->maxIndex = this->list.size() - 1;
	}
	else {
		this->maxIndex = 0;
	}
}

int DataComponent::getCurrIndex() {
	return this->currIndex;
}

void DataComponent::componentHoldMessage(string message) {
	this->holdDisplay(message, false);
}

void DataComponent::componentErrorMessage(string message) {
	this->holdDisplay(message, true);
}

void DataComponent::_display() {
	StreamHelper::cls();
	cout << this->title << endl;

	int i;
	for (i = 0; i < this->list.size(); i++) {
		if (this->currIndex == i) {
			cout << "> " << setiosflags(ios::left) << setw(30) << this->list[i]; cout.unsetf(0xffff);
		}
		else {
			cout << "  " << setiosflags(ios::left) << setw(30) << this->list[i]; cout.unsetf(0xffff);
		}
		cout << endl;
	}

	if (this->enableBack) {
		cout << endl << "Press ESC to back" << endl;
	}

	cout << this->footer << endl;
}

void DataComponent::_emit() {
	bool repeat = true;

	while (repeat) {
		if (kbhit()) {
			char ch = getch();
			switch (ch) {
			case StreamHelper::KEYDOWN:
				this->moveDown();
				this->_display();
				break;
			case StreamHelper::KEYUP:
				this->moveUp();
				this->_display();
				break;
			case StreamHelper::ENTER:
				this->isExit = true;
				this->isBack = false;
				repeat = false;
				break;
			case StreamHelper::ESC:
				this->isBack = true;
				this->isExit = false;
				repeat = false;
				break;
			}
		}
	}
}

void DataComponent::_init(string title, string footer, bool enableBack) {
	this->bindIndex();
	this->enableBack = enableBack;
	this->setTitle(title);
	this->setFooter(footer);

	this->_display();
	this->_emit();
}