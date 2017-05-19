#pragma once

#include "provider.h"

#include "transaction.model.h"

using namespace std;

class TransactionProvider : Provider {

private:
	vector<TransactionModel> transactions;
	TransactionModel transaction;

public:
	TransactionProvider();

	void bindTransactions();

	void bindTransaction();

	void setResult();

	vector<TransactionModel> all();

	int add(TransactionModel transaction);

	bool remove(TransactionModel transaction);

	bool update(TransactionModel transaction);

	int getIndex(int id);

	TransactionModel findById(int id);

	TransactionModel last();

	bool hasById(int id);

};