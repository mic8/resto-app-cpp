#include "validator.helper.h"

ValidatorHelper::ValidatorHelper() {
	this->bindRules();
	this->bindCheck();
}

void ValidatorHelper::bindRules() {
	this->rules.push_back("required");
	this->rules.push_back("min:0");
	this->rules.push_back("max:0");
}

void ValidatorHelper::bindCheck() {
	this->check.push_back(0);
	this->check.push_back(0);
	this->check.push_back(0);
}

void ValidatorHelper::matchRule(vector<string> rules) {
	int i, j;

	bool flag;

	for (i = 0; i < this->rules.size(); i++) {
		flag = false;

		size_t posA = this->rules[i].find(':');
		string col = this->rules[i].substr(0, posA);
		size_t posB = 1;
		string rule;

		for (j = 0; j < rules.size(); j++) {
			posB = rules[j].find(':');
			rule = rules[j].substr(0, posB);

			if (col == rule) {
				flag = true;
			}
		}

		if (flag) {
			this->check[i] = 1;
		}
	}

	if (this->check[ValidatorHelper::MIN]) {
		size_t minPos = rules[ValidatorHelper::MIN].find(':');
		string minStr = rules[ValidatorHelper::MIN].substr(minPos + 1, rules[ValidatorHelper::MIN].length());

		this->check[ValidatorHelper::MIN] = stoi(minStr);
	}

	if (this->check[ValidatorHelper::MAX]) {
		size_t maxPos = rules[ValidatorHelper::MAX].find(':');
		string maxStr = rules[ValidatorHelper::MAX].substr(maxPos + 1, rules[ValidatorHelper::MAX].length());

		this->check[ValidatorHelper::MAX] = stoi(maxStr);
	}
}

void ValidatorHelper::showErrorMessage(string message) {
	cout << "Validator exception: " << message; cin.get();
}