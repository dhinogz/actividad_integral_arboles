#include "NodeT.h"

class BST{
	public:
		BST();
		~BST();
		void add(dataCS data);
		void print();
		int repeat(const string &palabra);
	private:
		NodeT *root;
		void inOrdenC(NodeT *r);
		void destuye_Helper(NodeT *r);
		int repeat_Helper(NodeT *const nodo, const std::string &palabra);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destuye_Helper(root);
}

void BST::destuye_Helper(NodeT *r){
	if (r != nullptr){
		destuye_Helper(r->getLeft());
		destuye_Helper(r->getRight());
		delete r;
	}
}

void BST::add(dataCS data){
	if (root == nullptr){
		root = new NodeT(data);
	}
	else{
		NodeT *curr = root;
		NodeT *parent = nullptr;
		while (curr != nullptr){
			if (curr->getData() == data){
				return;
			}
			parent = curr;
			curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
		}
		parent->getData() > data ? parent->setLeft(new NodeT(data)) : parent->setRight(new NodeT(data));
	}
}

void BST::print(){
	inOrdenC(root);
	cout << endl;
}

void BST::inOrdenC(NodeT *r){
	if (r != nullptr){
		inOrdenC(r->getRight());
		cout << r->getData() << " ";
		inOrdenC(r->getLeft());
	}
}

int BST::repeat(const string &palabra){
    return repeat_Helper(root, palabra);
}

int BST::repeat_Helper(NodeT *const nodo, const std::string &palabra)
{
    if (nodo)
    {
        NodeT *curr = root;
        return repeat_Helper(nodo->getLeft(), palabra) + repeat_Helper(nodo->getRight(), palabra) + (nodo->getData().nombre == palabra ? 1 : 0);
    }
    return 0;
}

