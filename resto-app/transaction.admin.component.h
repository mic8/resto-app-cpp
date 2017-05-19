#pragma once

#include "menu.component.h"
#include "transaction.model.h"
#include "transaction.provider.h"

#include "vendor.admin.component.h"
#include "transaction-view.admin.component.h"

class TransactionAdminComponent : MenuComponent {

private:
	TransactionProvider transactionProvider;

public:
	void bindList();

	void bindTitle(string title);

	void viewTransactions();

	void action(int currIndex);

	void back();

	void init();

};