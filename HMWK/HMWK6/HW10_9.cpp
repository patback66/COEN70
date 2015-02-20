#include <iostream>
#include <iomanip>

using namespace std;

struct BSTNode {
	float data;
	BSTNode* lc;
	BSTNode* rc;
};

struct node {
	float data;
	node* next;
};

BSTNode* produceBalancedTree(node* head) {
	node* p = head;
	BSTNode *nBST = NULL;

	while (p != NULL) {
		BSTNode *nBT = new BSTNode;
		nBT -> data = p -> data;
		nBT -> lc = NULL;
		nBT -> rc = NULL;
		if (nBST == NULL) {
			nBST = nBT;
		} else {
			if (nBST -> rc == NULL) {
				nBST -> rc = nBT;
			} else {
				nBT -> lc = nBST;
				nBST = nBT;
			}
		}
		p = p -> next;
	}
	
	return nBST;
}

void print(BSTNode* r, int depth) {
	if (r != NULL)
	{
		print(r -> rc, depth + 1);
		cout << setw(4*depth) << "" << r -> data << endl;
		print(r -> lc, depth + 1);
	}
}

int main(int argc, char *argv[]) {
	node* head = new node;
	head -> data = 0;
	node *t = head;
	for(int i = 1; i <= 10; i++) {
		node* nNode = new node;
		nNode -> data = i;
		nNode -> next = NULL;
		t -> next = nNode;
		t = nNode;
	}
	
	BSTNode* bst = produceBalancedTree(head);
	
	print(bst, 0);
	
	return 0;
}