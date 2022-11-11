#pragma once

class Node {
public:

	int data;
	Node* left;
	Node* right;

	// Initializing values and pointers
	Node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}

	// Maipulate the tree
	void insertIntoTree(int tall);
	
	// Find things in the tree
	int getRoot();
	int getMin();
	int getMax();
	void searchForKey(int key);
	void displayTree();
};


inline void Node::insertIntoTree(int tall) {

	// very kul code. Does not not do duplicates :^)
	// Thank Mathis
	if (tall > this->data) {
		//return;
		// Insert node into position
		if (this->right == nullptr) {
			this->right = new Node(tall);
		}
		else {
			this->right->insertIntoTree(tall);
		}
	}
	else if (tall < this->data){
		//insertIntoTree(tall);
		if (this->left == nullptr) {
			this->left = new Node(tall);
			
		}
		else {
			this->left->insertIntoTree(tall);
		}
	}
}


int Node::getRoot() {
	return this->data;
}


inline int Node::getMin() {

	return 1;
}


inline int Node::getMax() {

	return 1;
}


inline void Node::searchForKey(int key) {
}


inline void Node::displayTree() {

}


