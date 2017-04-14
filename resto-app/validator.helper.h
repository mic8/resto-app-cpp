#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ValidatorHelper {

public:
	static const int REQUIRED = 0;
	static const int MIN = 1;
	static const int MAX = 2;

	ValidatorHelper();

	vector<string> rules;

	void bindRules();

	vector<int> check;

	void bindCheck();

	void matchRule(vector<string> rules);

	void showErrorMessage(string message);
	
};