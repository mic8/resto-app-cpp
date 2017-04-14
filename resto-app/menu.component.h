#pragma once

#include "component.h"

using namespace std;

class MenuComponent: Component {

private:
	int currIndex;

	int maxIndex;
	
	void moveUp();
	
	void moveDown();
	
	string title;

	bool enableBack;

protected:
	bool isBack;

	bool isExit;

	vector<string> list;

	void addList(string label);

	void setTitle(string title);

	void bindIndex();

	int getCurrIndex();

	void componentHoldMessage(string message);

	void componentErrorMessage(string message);

public:
	void _display();
	
	void _emit();

	void _init(bool enableBack);
};