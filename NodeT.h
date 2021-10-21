struct dataCS {
	int cant;
	string nombre;

	dataCS() {
		cant = 0;
		nombre = "AAA";
	}

	dataCS(int cant, string nombre) {
		this->cant = cant;
		this->nombre = nombre;
	}

	bool operator==(const dataCS &otra) {
		return this->cant == otra.cant && this->nombre == otra.nombre;
	}

	bool operator>(const dataCS &otra) {
		if (this->cant == otra.cant) {
			return this->nombre.compare(otra.nombre) < 0;
		}
		return this->cant > otra.cant;
	}

	void operator=(const dataCS &otra) {
		this->cant = otra.cant;
		this->nombre = otra.nombre;
	}
	friend ostream& operator<<(ostream& os, const dataCS &d);
};

ostream& operator<<(ostream& os, const dataCS &d){
	os << d.nombre << " " << d.cant << endl;
	return os;
}

class NodeT{
	public:
		NodeT(int data);
		NodeT(int data, NodeT *left, NodeT *right);
		int getData();
		NodeT* getLeft();
		NodeT* getRight();
		void setData(int data);
		void setLeft(NodeT *left);
		void setRight(NodeT *right);
	private:
		int data;
		NodeT *left;
		NodeT *right;
};

NodeT::NodeT(int data){
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

NodeT::NodeT(int data, NodeT *left, NodeT *right){
	this->data = data;
	this->left = left;
	this->right = right;
}

int NodeT::getData(){
	return data;
}

NodeT* NodeT::getLeft(){
	return left;
}

NodeT* NodeT::getRight(){
	return right;
}

void NodeT::setData(int data){
	this->data = data;
}

void NodeT::setLeft(NodeT *left){
	this->left = left;
}

void NodeT::setRight(NodeT *right){
	this->right = right;
}







