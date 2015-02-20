template <typename T>
void BST<T>::dealloc(node* n) {
	if (n != NULL)
	{
		dealloc(n -> lc);
		dealloc(n -> rc);
		delete n;
	}
}

template <typename T>
BST& BST<T>::operator=(const BST& rhs) {
	if (this != &rhs)
	{
		dealloc(r);
		r = copy(other.r);
		size = other.size;
	}
	return *this;
}

template <typename T>
typename BST<T>::node* BST<T>::copy(node* r) {
	node* n = NULL;
	if (r != NULL)
	{
		n = new node(r.d, copy(r -> lc), copy(r -> rc));
	}
	return n;
}

//Print out a binary Tree
//V1
void print(node* r, int depth) {
	if (r != NULL)
	{
		print(r -> rc, depth + 1);
		cout << setw(4*depth) << "" << r -> d << endl;
		print(r -> lc, depth + 1);
	}
}

//V2
void print(node* r) {
	if (r == NULL)
	{
		cout << ".";
	} else {
		cout << "(";
		print(r -> lc);
		cout << r -> d;
		print(r -> rc);
		cout << ")";
	}
}

template <typename T>
bool BST<T>::insert(node* x) {
	node* t = r;
	while ( t != NULL) {
		if (x < t -> d)
		{
			if (t -> lc == NULL) 
			{
				t -> lc = new node(x);
				return true;
			}
			t = t -> lc;
		} else {
			if (t -> rc == NULL) 
			{
				t -> rc = new node(x);
				return true;
			}
			t = t -> rc;
		}
	}
	r = new node(x);
	return true;
}

template <typename T>
bool BST<T>::remove(const T& x, node*& p = r) {
	if (p == NULL)
	{
		return false;
	}
	if (isLeaf(p) && p -> d == x)
	{
		delete p;
		p = NULL;
		return true;
	}

	node* t = p;
	while(t != NULL && t -> d != x) {
		if (t -> d < x)
		{
			t = t -> rc;
		} else {
			t = t -> lc;
		}
	}
	if (t == NULL)
		return false;

	node* f = predecessor(t -> lc);
	if (f == NULL)
	{
		if (isLeaf(t))
		{
			remove(t->d,t);
		} else {
			t -> d = t -> rc -> d;
			t -> lc = t -> lc;
			node* trc = t -> rc;
			t -> rc = trc -> rc;
			delete trc;
		}
	} else {
		t -> d = f -> d;
		remove(f -> d, f);
	}
}