#ifndef MAIN_SAVITCH_BAG3_H
#define MAIN_SAVITCH_BAG3_H
#include <cstdlib>   // Provides size_t and NULL

class node {
    public:
		// TYPEDEF
		typedef double value_type;
	    
		// CONSTRUCTOR
		node(
		    const value_type& init_data = value_type( ),
		    node* init_link = NULL
		)
		{ data_field = init_data; link_field = init_link; }

		// Member functions to set the data and link fields:
	    	void set_data(const value_type& new_data) { data_field = new_data; }
	    	void set_link(node* new_link)             { link_field = new_link; }

		// Constant member function to retrieve the current data:
		value_type data( ) const { return data_field; }

		// Two slightly different member functions to retreive
		// the current link:
		const node* link( ) const { return link_field; }
	    	node* link( )             { return link_field; }
    private:
		value_type data_field;
		node* link_field;
};

class bag
{
	public:
		// TYPEDEFS
		typedef std::size_t size_type;
		typedef node::value_type value_type;
		// CONSTRUCTORS and DESTRUCTOR
		bag( );
		bag(const bag& source);
		~bag( );
		// MODIFICATION MEMBER FUNCTIONS
		size_type erase(const value_type& target);
		bool erase_one(const value_type& target);
		void insert(const value_type& entry);
		void operator +=(const bag& addend);
		void operator =(const bag& source);
		// CONSTANT MEMBER FUNCTIONS
		size_type size( ) const { return many_nodes; }
		size_type count(const value_type& target) const;
		value_type grab( ) const;
	private:
		node *head_ptr;       // List head pointer 
		size_type many_nodes; // Number of nodes on the list
};

// NONMEMBER FUNCTIONS for the bag class:    
bag operator +(const bag& b1, const bag& b2);

#endif