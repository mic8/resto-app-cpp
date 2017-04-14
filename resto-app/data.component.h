#pragma once

#include "component.h"

class DataComponent: Component {

private:
	int currIndex;

	int maxIndex;

	void moveUp();

	void moveDown();

	string title;

	string footer;

	bool enableBack;

protected:
	bool isBack;

	bool isExit;

	vector<string> list;

	void addList(string label);

	void setTitle(string title);

	void setFooter(string footer);

	void bindIndex();

	int getCurrIndex();

	void componentHoldMessage(string message);

	void componentErrorMessage(string message);

public:
	void _display();

	void _emit();

	void _init(string title, string footer, bool enableBack);

};