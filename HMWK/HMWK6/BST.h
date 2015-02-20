template <typename T>
class BST {
	protected:
		struct node {
				node(T v = T(), node* left = NULL, node* right = NULL):d(v),lc(left),rc(right){};
				node* lc;
				node* rc;
				T d;
		};
		node* r;
		int size;
		void dealloc(node*);
	public:
		BST(){ r = NULL; size = 0;};
		BST(const BST& other){ r = NULL; *this = other};
		~BST(){ dealloc(r) };
		BST& operator= (const BST&);

		bool insert(const T&);
		bool remove(const T&);
		void remove_all(const T&);

		bool contains(const T&);
		int size(){return size};
};