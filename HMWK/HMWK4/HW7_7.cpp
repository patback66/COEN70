#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>

using namespace std;

void processInput(const string& str, vector<string>& storage, vector<string>& operators)
{
	string::size_type last = 0;
	for(string::size_type i = 0; i < str.length(); i++) {
		if (str[i] == '&' && ((i + 1) < str.length()) && str[i + 1] == '&') {
			//Find the &&
			string sub = str.substr(last, (i - last));
			storage.push_back(sub);
			operators.push_back("&&");
			i++;
			last = i + 1;
			continue;
		}
		if (str[i] == '|' && ((i + 1) < str.length()) && str[i + 1] == '|') {
			//Find the &&
			string sub = str.substr(last, (i - last));
			storage.push_back(sub);
			operators.push_back("||");
			i++;
			last = i + 1;
			continue;
		}
	}
	if (last < str.length()) {
		string sub = str.substr(last, (str.length() - last));
		storage.push_back(sub);
	}
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

bool evaluateBooleanExpression(string& s) {
	string::size_type begin = s.find("(");
	string::size_type end = s.find(")");
	
	string content = s.substr(begin + 1, end - begin - 1);
	
	vector<string> st;
	Tokenize(content, st);
	
	if (st.size() != 3) {
		throw "Unexcepted Size";
	}
	
	int value1 = atoi(st[0].c_str());
	int value2 = atoi(st[2].c_str());
	
	if (st[1] == "<") {
		return (value1 < value2);
	} else if (st[1] == ">") {
		return (value1 > value2);
	} else if (st[1] == "<=") {
		return (value1 <= value2);
	} else if (st[1] == ">=") {
		return (value1 >= value2);
	} else if (st[1] == "==") {
		return (value1 == value2);
	} else if (st[1] == "!=") {
		return (value1 != value2);
	}
	
	return false;
}

bool evaluateExpression(istream& ins) {
	vector<string> storage;
	vector<string> operators;
	
	string input;
	getline(ins, input);
	processInput(input, storage, operators);
	
	stack<bool> r;
	stack<string> op;
	
	for (int i = 0; i < storage.size(); i++) {
		if (i % 2 == 0) {
			op.push(operators.front());
			operators.erase(operators.begin());
		}
		r.push(evaluateBooleanExpression(storage[i]));
	}
	
	while (!op.empty()) {
		bool v1 = r.top();
		r.pop();
		bool v2 = r.top();
		r.pop();
		string operat = op.top();
		op.pop();
		if (operat == "&&") {
			r.push(v1 && v2);
			continue;
		}
		if (operat == "||") {
			r.push(v1 || v2);
			continue;
		}
	}
	
	return r.top();
}

int main(int argc, char *argv[]) {
	cout << evaluateExpression(cin) << endl;
	//(3 > 5) && (2 > 1) should output 0
	//(3 > 5) || (2 > 1) should output 0
	//(3 < 5) && (2 > 1) should output 1
	
	return 0;
}