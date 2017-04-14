#pragma once

#include "menu.component.h"

class SelectComponent: MenuComponent {

public:
	void bindList(vector<string> list);

	void bindTitle(string title);

	int init(vector<string> list, string title);

};