#pragma once

#include "data.component.h"

#include "transaction.model.h"
#include "transaction.provider.h"
#include "transaction.admin.component.h"
#include "transaction-detail.admin.component.h"

class TransactionViewAdminComponent : DataComponent {

private:
	stringstream titleView;

	vector<TransactionModel> transactions;

	TransactionModel transaction;

	TransactionProvider transactionProvider;

public:
	void bindTransactions();

	void bindTitle();

	void bindList();

	string header();

	void action(int currIndex);

	void init();

	void doUpdateTransaction();

};