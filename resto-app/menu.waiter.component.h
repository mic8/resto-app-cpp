#pragma once

#include "data.component.h"

#include "menu.model.h"
#include "transaction.model.h"
#include "transaction-detail.model.h"

#include "menu.provider.h"
#include "transaction.provider.h"
#include "transaction-detail.provider.h"
#include "vendor.waiter.component.h"

class MenuWaiterComponent : DataComponent {

private:
	stringstream titleView;

	vector<MenuModel> menus;

	MenuModel menu;

	MenuProvider menuProvider;

	int transactionId;
	TransactionProvider transactionProvider;
	TransactionDetailProvider transactionDetailProvider;

public:
	void bindMenus();

	void bindTitle();

	void bindList();

	string header();

	void action(int currIndex);

	void init();

	void reset();

	void doCreateTransaction();

	void doChooseMenu();

};