#pragma once

#include "stream.helper.h"
#include <iomanip>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

class Component {

protected:
	void holdDisplay(string message, bool isError);

	void componentHoldMessage(string message);

	void componentErrorMessage(string message);

};