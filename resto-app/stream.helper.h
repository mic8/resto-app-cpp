#pragma once

#include <iostream>
#include <Windows.h>
#include <sstream>

#include "validator.helper.h"

using namespace std;

class StreamHelper {

private:
	static const int range = 30;

public:
	static const char KEYUP = 0x48;
	static const char KEYDOWN = 0x50;
	static const char ENTER = 13;
	static const char ESC = 27;
	static const char UNSET = 0xffff;

	static void cls();

	static void hold();

	static string stringValidator(string any, string label, vector<string> args);

	//static int intValidator(int any, string label, vector<string> args);

	//static double doubleValidator(double any, string label, vector<string> args);

};