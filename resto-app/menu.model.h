#pragma once

#include <iostream>
#include <string>

using namespace std;

class MenuModel {

protected:
	int id;
	string name;
	double price;
	int qty;

public:
	int getId();

	void setId(int id);

	string getName();

	void setName(string name);

	double getPrice();

	void setPrice(double price);

	int getQty();

	void setQty(int qty);

};