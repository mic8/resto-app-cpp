#include "stream.helper.h"

void StreamHelper::cls() {
	system("cls");
}

void StreamHelper::hold() {
	cin.get();
}

string StreamHelper::stringValidator(string any, string label, vector<string> args) {
	ValidatorHelper validator;
	validator.matchRule(args);

	if (validator.check[ValidatorHelper::REQUIRED]) {
		do {
			StreamHelper::cls();
			cout << label;
			getline(cin, any); cin.sync(); cin.clear();
			if (any.length() == 0) validator.showErrorMessage("Input is Required");
			if (any.length() < validator.check[ValidatorHelper::MIN] && any.length() != 0) validator.showErrorMessage("Input must has minimal " + to_string(validator.check[ValidatorHelper::MIN]) + " input(s)");
			if (any.length() > validator.check[ValidatorHelper::MAX]) validator.showErrorMessage("Input must has maximal " + to_string(validator.check[ValidatorHelper::MAX]) + " input(s)");
		} while (any.length() == 0 || any.length() < validator.check[ValidatorHelper::MIN] || any.length() > validator.check[ValidatorHelper::MAX]);
	}
	else {
		do {
			StreamHelper::cls();
			cout << label;
			getline(cin, any); cin.sync(); cin.clear();
			if (any.length() < validator.check[ValidatorHelper::MIN] && any.length() != 0) validator.showErrorMessage("Input must has minimal " + to_string(validator.check[ValidatorHelper::MIN]) + " input(s)");
			if (any.length() > validator.check[ValidatorHelper::MAX]) validator.showErrorMessage("Input must has maximal " + to_string(validator.check[ValidatorHelper::MAX]) + " input(s)");
		} while (any.length() < validator.check[ValidatorHelper::MIN] || any.length() > validator.check[ValidatorHelper::MAX]);
	}

	return any;
}

//int StreamHelper::intValidator(int any, string label, vector<string> args) {
//	ValidatorHelper validator;
//	validator.matchRule(args);
//
//	if (validator.check[ValidatorHelper::REQUIRED]) {
//		do {
//			StreamHelper::cls();
//			cout << label;
//			cin >> any; cin.sync(); cin.clear();
//			if (any) validator.showErrorMessage("Input is Required");
//			if (any < validator.check[ValidatorHelper::MIN] && any != 0) validator.showErrorMessage("Input must has minimal " + to_string(validator.check[ValidatorHelper::MIN]) + " input(s)");
//			if (any > validator.check[ValidatorHelper::MAX]) validator.showErrorMessage("Input must has maximal " + to_string(validator.check[ValidatorHelper::MAX]) + " input(s)");
//		} while (any <= 0 || any < validator.check[ValidatorHelper::MIN] || any > validator.check[ValidatorHelper::MAX]);
//	}
//	else {
//		do {
//			StreamHelper::cls();
//			cout << label;
//			cin >> any; cin.sync(); cin.clear();
//			if (any < validator.check[ValidatorHelper::MIN] && any != 0) validator.showErrorMessage("Input must has minimal " + to_string(validator.check[ValidatorHelper::MIN]) + " input(s)");
//			if (any > validator.check[ValidatorHelper::MAX]) validator.showErrorMessage("Input must has maximal " + to_string(validator.check[ValidatorHelper::MAX]) + " input(s)");
//		} while (any < validator.check[ValidatorHelper::MIN] || any > validator.check[ValidatorHelper::MAX]);
//	}
//
//	return any;
//}
//
//double StreamHelper::doubleValidator(double any, string label, vector<string> args) {
//	ValidatorHelper validator;
//	validator.matchRule(args);
//
//	if (validator.check[ValidatorHelper::REQUIRED]) {
//		do {
//			StreamHelper::cls();
//			cout << label;
//			cin >> any; cin.sync(); cin.clear();
//			if (any) validator.showErrorMessage("Input is Required");
//			if (any < validator.check[ValidatorHelper::MIN] && any != 0) validator.showErrorMessage("Input must has minimal " + to_string(validator.check[ValidatorHelper::MIN]) + " input(s)");
//			if (any > validator.check[ValidatorHelper::MAX]) validator.showErrorMessage("Input must has maximal " + to_string(validator.check[ValidatorHelper::MAX]) + " input(s)");
//		} while (any <= 0 || any < validator.check[ValidatorHelper::MIN] || any > validator.check[ValidatorHelper::MAX]);
//	}
//	else {
//		do {
//			StreamHelper::cls();
//			cout << label;
//			cin >> any; cin.sync(); cin.clear();
//			if (any < validator.check[ValidatorHelper::MIN] && any != 0) validator.showErrorMessage("Input must has minimal " + to_string(validator.check[ValidatorHelper::MIN]) + " input(s)");
//			if (any > validator.check[ValidatorHelper::MAX]) validator.showErrorMessage("Input must has maximal " + to_string(validator.check[ValidatorHelper::MAX]) + " input(s)");
//		} while (any < validator.check[ValidatorHelper::MIN] || any > validator.check[ValidatorHelper::MAX]);
//	}
//
//	return any;
//}