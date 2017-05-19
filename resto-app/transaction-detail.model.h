#pragma once

#include <iostream>
#include <string>

using namespace std;

class TransactionDetailModel {

protected:
	int id;
	int transaction;
	int menu;
	int qty;

public:
	int getId();

	void setId(int id);

	int getTransaction();

	void setTransaction(int id);

	int getMenu();

	void setMenu(int id);

	int getQty();

	void setQty(int qty);

};