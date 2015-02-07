#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool higherOrder(const char& c1, const char& c2) {
	if (c1 == '*' || c1 == '/') {
		if (c2 == '+' || c2 == '-') {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

bool isOperator(const string& c) {
	if (c.length() != 1) {
		return false;
	}
	
	if (c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/') {
		return true;
	}
	return false;
}

void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos     = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
			tokens.push_back(str.substr(lastPos, pos - lastPos));
			lastPos = str.find_first_not_of(delimiters, pos);
			pos = str.find_first_of(delimiters, lastPos);
	}
}

string convertInfix(string in) {
	string output;
	stack<string> s;
	
	vector<string> tokens;
	
	Tokenize(in, tokens);
	
	for (int i = 0;i < tokens.size();i++) {
		string c = tokens[i];
		if (c.length() == 1 && c[0] == '(') {
			s.push(c);
		}else if (!isOperator(c) && c != ")") {
			output += c;
			output += " ";
		} else if (isOperator(c)) {
			while (!s.empty() && s.top() != "(" && !higherOrder(c[0], s.top()[0])) {
				output += s.top();
				output += " ";
				s.pop();
			}
			s.push(c);
		} else {
			if (c == ")") {
				while (!s.empty()) {
					output += s.top();
					output += " ";
					s.pop();
					if (!s.empty() && s.top() == "(") {
						s.pop();
						break;
					}
				}
			}
		}
	}
	
	while (!s.empty()) {
		if (s.top() != "(") {
			output += s.top();
			output += " ";
		}
		s.pop();

	}
		
	return output;
}

int main(int argc, char *argv[]) {
	string input;
	getline(cin, input);
	string out = convertInfix(input);
	
	cout << out << endl;
	
	return 0;
}