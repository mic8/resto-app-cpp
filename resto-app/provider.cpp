#include "provider.h"

vector<vector<string>> Provider::files() {
	ifstream inFile(this->filePath);
	vector<vector<string>> arr;

	if (inFile.is_open()) {
		string row, col;

		int i = 0;
		while (getline(inFile, row)) {
			size_t pos = 1;
			arr.push_back(vector<string>());
			while ((pos = row.find(this->delimiter)) != string::npos) {
				col = row.substr(0, pos);
				arr[i].push_back(col);
				row.erase(0, pos + this->delimiter.length());
			}
			i++;
		}
	}
	else {
		this->errorFileNotExists();
	}

	return arr;
}

void Provider::save() {
	ofstream outFile(this->filePath);

	if (outFile.is_open()) {
		int i;
		for (i = 0; i < this->result.size(); i++) {
			if (i == this->result.size() - 1) {
				outFile << this->result[i] << ",";
			}
			else {
				outFile << this->result[i] << "," << endl;
			}
		}

		outFile.close();
	}
	else {
		this->errorFileNotExists();
	}
}

void Provider::setPath(string filePath) {
	this->filePath = this->dataPath + '/' + filePath;
}

void Provider::errorFileNotExists() {
	cout << "Error filestream: " << this->fileNotExistsMessage << endl;
}