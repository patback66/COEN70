
class BST {
    protected:
        class node {
            node* left;
            node* right;
            T data;
            node(int d, node* lc = NULL, node* rc = NULL) { data(d), left(lc), right(rc);}
        };
        node* r;
    public:
        BST() {
            root = NULL;
        }
        bool isEmpty() const {return r==NULL;}
        void insert(int);
        void remove(int);

};