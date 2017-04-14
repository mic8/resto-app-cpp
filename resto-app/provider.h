#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Provider {

private :
	string fileNotExistsMessage = "File not exists";

protected:
	string dataPath = "Data";
	
	string filePath;
	
	string delimiter = ",";
	
	vector<string> result;

	vector<vector<string>> files();
	
	void save();
	
	void setPath(string filePath);
	
	void errorFileNotExists();

};