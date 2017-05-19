#pragma once

#include "data.component.h"

#include "transaction.model.h"
#include "transaction-detail.model.h"
#include "transaction-detail.provider.h"
#include "transaction.admin.component.h"

class TransactionDetailAdminComponent : DataComponent {

private:
	stringstream titleView;

	vector<TransactionDetailModel> transactions;

	TransactionDetailModel transactionDetail;

	TransactionDetailProvider transactionDetailProvider;

public:
	void bindTransactionDetails(TransactionModel transaction);

	void bindTitle();

	void bindList();

	string header();

	void action(int currIndex);

	void init(TransactionModel transaction);

};