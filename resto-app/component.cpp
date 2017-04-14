#include "component.h"

void Component::holdDisplay(string message, bool isError = false) {
	bool repeat = true;

	cout << endl;
	if (isError) {
		cout << message << endl << "Press ENTER to back...";
	}
	else {
		cout << message << endl << "Press ENTER to continue...";
	}

	cout << endl;

	while (repeat) {
		if (kbhit()) {
			char ch = getch();
			if (ch == StreamHelper::ENTER) {
				repeat = false;
				break;
			}
		}
	}
}

void Component::componentHoldMessage(string message) {
	this->holdDisplay(message, false);
}

void Component::componentErrorMessage(string message) {
	this->holdDisplay(message, true);
}