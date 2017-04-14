#include "stream.helper.h"
#include "menu.component.h"

void MenuComponent::moveUp() {
	if (this->currIndex > 0) this->currIndex--;
	this->_display();
}

void MenuComponent::moveDown() {
	if (this->currIndex < this->maxIndex) this->currIndex++;
	this->_display();
}

void MenuComponent::addList(string label) {
	this->list.push_back(label);
}

void MenuComponent::setTitle(string title) {
	this->title = title;
}

void MenuComponent::bindIndex() {
	this->currIndex = 0;
	if (this->list.size() != 0) {
		this->maxIndex = this->list.size() - 1;
	}
}

int MenuComponent::getCurrIndex() {
	return this->currIndex;
}

void MenuComponent::componentHoldMessage(string message) {
	this->holdDisplay(message, false);
}

void MenuComponent::componentErrorMessage(string message) {
	this->holdDisplay(message, true);
}

void MenuComponent::_display() {
	StreamHelper::cls();
	int i;
	cout << this->title << endl << endl;
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
}

void MenuComponent::_emit() {
	if (this->list.size() != 0) {
		bool repeat = true;

		while (repeat) {
			if (kbhit()) {
				char ch = getch();
				switch (ch) {
				case StreamHelper::KEYUP:
					this->moveUp();
					break;
				case StreamHelper::KEYDOWN:
					this->moveDown();
					break;
				case StreamHelper::ENTER:
					repeat = false;
					this->isExit = true;
					break;
				case StreamHelper::ESC:
					if (this->enableBack) {
						repeat = false;
						this->isBack = true;
						break;
					}
				}
			}
		}
	}
}

void MenuComponent::_init(bool enableBack) {
	this->isBack = false;
	this->enableBack = enableBack;

	this->bindIndex();

	this->_display();
	this->_emit();
}