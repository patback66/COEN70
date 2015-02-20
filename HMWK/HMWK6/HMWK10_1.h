#include
using namespace std;

template <typename T>
class eTree : public BST {
	protected:

	public:
		eTree(){;
		eTree(const eTree& other){ r = NULL; *this = other};
		~eTree(){ dealloc(r) };
		eTree& operator= (const eTree&);

		bool insert(const T&);

		double evaluate(node* n);
		bool isOperator(node* n);
		bool iseaf(const node& n);
};