#include <iostream>
#include <vector>

using namespace std;


//Print Solution
void printSol(const vector<int>& q, int N) {
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			if (q[i] == j) {
				cout << "1";
			} else {
				cout << "0";
			}
		}
		cout<<endl;
	}
	cout << "-----" << endl;
}

//Check and see if passed in vector is a soultion
bool isSolution(const vector<int>& q, int N) {
	return (q.size() == N);
}

//Check and see if row and col is safe
bool isSafe(const vector<int>&q, int r, int c, int N) {
	for (int i = 0;i < q.size(); i++) {
		//Check if they are in same row or col
		if (i == r || q[i] == c) {
			return false;
		}
		//Check diagonal 
		if (abs(i - r) == abs(q[i] - c)) {
			return false;
		}
	}
	return true;
}

//Construct a potential location
bool createPotential(const vector<int>& q, int r, int N, vector<int>& p) {
	for (int i = 0;i < N; i++) {
		if(isSafe(q, r, i, N)) {
			p.push_back(i);
		}
	}
	return (p.size() > 0);
}

//Find Solution
void backtrack(vector<int>& q, int r, int N) {
	if (isSolution(q,N)) {
		printSol(q,N);
	} else {
		vector<int> potential;
		if (createPotential(q, r, N, potential)) {
			for (int i = 0 ;i < potential.size(); i++) {
				q.push_back(potential[i]);
				backtrack(q, r + 1, N);
				q.pop_back();
			}
		}
	}
}

void nQueens(int n) {
	vector<int> queens;
	backtrack(queens, 0, n);
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	nQueens(n);
	return 0;
}