class List {	
    public:	
        //Function:	Constructors	
        List();	
        //Function:	Destructor	
        ~List();	
        //Function:	Copy constructor	
        List(const List&);	
        //Function:	Assignment operator	
        const List&	operator=(const	List&);	
        //Function:	output	operator	
        friend ostream&	operator<<(ostream&, const List&);	
        //Function:	Insert an item to the list	
        //Postcondition: insert	after the pointer and	
        //move the pointer to the new item	
        void insert(const int&);	
        class node {	
            node(int, node*);	
            int data;	
            node* next;	
         };
    private:	
        node* list;	
        int	size;	
        node* cursor;	
};	