class stack {
    public:
        stack();
        ~stack();
        void push(double);
        double pop();
        bool empty();
    private:
        int size;
       
        class node {
            public:
                node(double, node* = NULL);
                double data;
                node* next;
        };
        node* list;
};