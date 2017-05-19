#pragma once

#include "provider.h"

#include "transaction-detail.model.h"

using namespace std;

class TransactionDetailProvider : Provider {

private:
	vector<TransactionDetailModel> transactions;
	TransactionDetailModel transaction;

public:
	TransactionDetailProvider();

	void bindTransactions();

	void bindTransaction();

	void setResult();

	vector<TransactionDetailModel> all();

	bool add(TransactionDetailModel transactionDetail);

	bool remove(TransactionDetailModel transactionDetail);

	bool update(TransactionDetailModel transactionDetail);

	int getIndex(int id);

	TransactionDetailModel findById(int id);

	TransactionDetailModel last();

	bool hasById(int id);

};