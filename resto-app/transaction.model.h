#pragma once

#include <iostream>
#include <string>

using namespace std;

class TransactionModel {

protected:
	int id;
	string status;

public:
	int getId();

	void setId(int id);

	string getStatus();

	void setStatus(string status);

};