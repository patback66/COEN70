#include <iostream>
#include <vector>

using namespace std;

/*
Parses a string for the given delimiter. Stores each partition between delimiters
in the vector storage.
*/
void tokenize(const string& str, const string& delimiter, vector<string>& storage) {
	bool inString = false;
	int begin = 0;
	int end = 0;
	//search the entire string
	for (int i = 0; i < str.length(); i++)
	{
		//check for the delimiter
		if (str[i] == delimiter[0])
		{
			inString = true;
			begin = i;
			int b = i + 1;
			int delIndex = 1;
			bool shouldEnd = false;
			//get the partition between delimiter
			if (delimiter.size() > 1) {
				while(inString && !shouldEnd) {
					if (str[b] == delimiter[delIndex])
					{
						b += 1;
						delIndex += 1;
						if (b > delimiter.length())
						{
							shouldEnd = true;
						}
					} else {
						inString = false;
					}
				}
			}
			if (inString)
			{
				string subStr = str.substr(end, (begin - end));
				end = b;
				storage.push_back(subStr);
				inString = false;
			}
		}
	}
	string subStr = str.substr(end);
	storage.push_back(subStr);
}

int main(int argc, char *argv[]) {
	string aStr = "This is a simple test.";
	string bStr = " ";
	vector<string> storage;
	
	tokenize(aStr, bStr, storage);
	cout << storage.size() << endl;
	for (int i = 0;i < storage.size();i++) {
		cout << storage[i] << endl;
	}
	return 0;	
}