/*
Addison Fattor & Matthew Koken
COEN 70L - Mon - 5:10
Lab 9
*/

#include "RBNode.h"

using namespace std;

class RBTree {
private:
	RBNode<int>* head;
public:
    RBTree() {
        head=NULL;
    }
    ~RBTree() {
        clear(head);
    }
    void clear(RBNode<int>* r) {
        if (r==NULL) return;
        clear(r->left());           //KILL YOUR
        clear(r->right());          //CHILDREN
        delete r;                   //Then yourself
    }
	void printTree() {
		print(head);                //recursive helper function
	}
	void print(RBNode<int>* r) {
		if (r==NULL) return;        //Preorder traversal
		cout<<r->data()<<" ";
		print(r->left());
		print(r->right());
	}
	void addNode(int x) {
		RBNode<int>* p = head;
		RBNode<int>* q = head;
        bool isRight;
		while(p!=NULL) {                    //Traverse until you get to where you need to add
			if (p!=NULL && x<p->data()) {   //If it's smaller, go to left
				q=p;
				p=p->left();
                isRight=false;
			}
			else if (p!=NULL && x>p->data()) {  //If it's larger, go to right
				q=p;
				p=p->right();
                isRight=true;
			}
			else
				break;
		}
		if (p==NULL) {              //Insert here
			p=new RBNode<int>(x);
			p->set_parent(q);
            if (q!=NULL) {
                if (isRight) q->set_right(p);
                else q->set_left(p);
            }
			fixTree(p);
            if (head==NULL) head=p;     //If tree was empty
			return;
		}
		if (x==p->data())           //Number is already in tree
			return;
	}
	RBNode<int>* getSibling(RBNode<int>* p) {
		RBNode<int>* q = p->parent();
		if (q==NULL)
			return NULL;
		if (p==q->left())
			return q->right();
		return q->left();
	}
	RBNode<int>* getAunt(RBNode<int>* p) {
		RBNode<int>* q = p->parent();
		if (q==NULL)
			return NULL;
		return getSibling(q);
	}
	RBNode<int>* getGrandparent(RBNode<int>* p) {
		RBNode<int>* q = p->parent();
		if (q==NULL)
			return NULL;
		return q->parent();
	}
	void rotateLeft(RBNode<int>* q) {
		RBNode<int>* r = q->right();
		RBNode<int>* p = q->parent();
		q->set_right(r->left());
		r->set_left(q);
		if (p!=NULL && p->left()==q)
			p->set_left(r);
		else if(p!=NULL)
			p->set_right(r);
		r->set_parent(p);
		q->set_parent(r);
        head=r;
	}
	void rotateRight(RBNode<int>* q) {
		RBNode<int>* l = q->left();
		RBNode<int>* p = q->parent();
		q->set_left(l->right());
		l->set_right(q);
		if (p!=NULL && p->left()==q)
			p->set_left(l);
		else if (p!=NULL)
			p->set_right(l);
		l->set_parent(p);
		q->set_parent(l);
	}
	void fixTree(RBNode<int>* current) {
		if (current->parent() == NULL) {        //If at root, change color to BLACK
			current->set_color(RBNode<int>::BLACK);
			return;
		}
		RBNode<int>* p = current->parent();
		if (p->color()==RBNode<int>::BLACK)     //If parent is BLACK, no fixing needed
			return;
		if (current->color()==RBNode<int>::RED) {   //If current is RED
			RBNode<int>* a = getAunt(current);
			RBNode<int>* gp = getGrandparent(current);
			if (a==NULL || a->color()==RBNode<int>::BLACK) {    //If aunt exists and is BLACK
				if (gp->left()==p) {
					if (p->right()==current) {
						rotateLeft(p);
						fixTree(p);
					}
					else {          //current is left: fix colors, rotate right
						p->set_color(RBNode<int>::BLACK);
						gp->set_color(RBNode<int>::RED);
						rotateRight(gp);
						return;
					}
				}
				else {              //parent is right
					if (p->left()==current) {
						rotateRight(p);
						fixTree(p);
					}
					else {          //current is right: fix colors, rotate left
						p->set_color(RBNode<int>::BLACK);
						gp->set_color(RBNode<int>::RED);
						rotateLeft(gp);
						return;
					}
				}
			}
			else {          //If aunt is RED: fix colors, fix tree
				p->set_color(RBNode<int>::BLACK);
				a->set_color(RBNode<int>::BLACK);
				gp->set_color(RBNode<int>::RED);
				fixTree(gp);
			}
		}
	}
};
