#include <iostream>
#include <fstream>

using namespace std;

//Helper function
void outputLine(ofstream& out, const int indents, const string& line) {
	for (int i = 0; i < indents; i++) {
		out << "  ";
	}
	out << line << endl;
}

//Input Filename, Output Filename
void processFile(const string& in, const string& out) {
	ifstream inFile;
	inFile.open(in);
	
	if (!inFile) {
		cout << "Input file doesn't exist." << endl;
		return;
	}
	
	ofstream outFile;
	outFile.open(out);
	
	if (!outFile) {
		cout << "An error occurred while opening output file." << endl;
		return;
	}
	
	int currentIndent = 0;
	
	while (!inFile.eof()) {
		string line;
		getline(inFile, line);
		
		//Remove potential indents
		string::size_type index = line.find_first_not_of(" \t");
		if (index != string::npos) {
			line = line.substr(index);
		}
		
		//Check if line contains "{"
		index = line.find("{");
		if (index != string::npos) {
			outputLine(outFile, currentIndent, line);
			currentIndent ++;
			continue;
		}
		
		//Check if line contains "}"
		index = line.find("}");
		if (index != string::npos) {
			//Adjust current Indents
			currentIndent --;
			outputLine(outFile, currentIndent, line);
			continue;
		}
		outputLine(outFile, currentIndent, line);
	}
	
	inFile.close();
	outFile.close();
}

int main(int argc, char *argv[]) {
	//Input Filename, Output Filename
	processFile("test.cpp", "test2.cpp");
	return 0;
}