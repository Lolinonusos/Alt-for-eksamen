#pragma once

class Node {
public:

	int data{};
	Node* left;
	Node* right;

	// Initializing values and pointers
	Node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}

	// These first functions will be used to manipulate nodes in the tree

	// Inserts a value into the tree
	void insertIntoTree(int key) {

		// very kul code. Does not not do duplicates :^)
		// Thank for explain Mathis
		if (key < this->data) {
			if (this->left == nullptr) {
				this->left = new Node(key);
			}
			else {
				this->left->insertIntoTree(key);
			}
		}
		else if (key > this->data) {
			if (this->right == nullptr) {
				this->right = new Node(key);
			}
			else {
				this->right->insertIntoTree(key);
			}
		}
	}

	// Useless function do not use
	// Was only made for training
	void removeMin() {

		Node* toDelete{ this };
		Node* secondToLast{ nullptr };
		if (toDelete != nullptr) {
			while (toDelete->left != nullptr) {
				secondToLast = toDelete;
				toDelete = toDelete->left;
			}
		}   

		std::cout << "Minimum is to delete is " << toDelete->data << std::endl;
		secondToLast->left = nullptr; // Wah, wah dereferencing NULL pointer waaah
		delete toDelete;
	}

	// Removes a value from the tree
	Node* remove(int key) {
		
		// End early if the current node does not exist
		if (this == nullptr) {
			return this;
		}

		// Find the node to be removed
		// Is important that left/right pointers are connected to the next nodes
		if (key < this->data) {
			this->left = this->left->remove(key);
		}
		else if (key > this->data) {
			this->right = this->right->remove(key);
		}
		else {
			
			// Node is found and has only one or no child nodes
			// If no nodes returns a nullpointer for the previous recursion
			if (this->left == nullptr) {
				Node* tmp = this->right;
				delete this;
				return tmp;
			}
			else if (this->right == nullptr) {
				Node* tmp = this->left;
				delete this;
				return tmp;
			}

			// Node has two child nodes
			// Find node with lowest value from the node we are going to delete
			Node* tmp = findMin(this->right);
		
			// Overwrite data in the node we originally wanted to delete
			// with the data from the node with lowest value
			this->data = tmp->data;

			// Then delete the node that held the lowest value
			this->right->remove(tmp->data);
		}
		return this;
	}


	// Functions from here are used to find things in the tree

	// Returns the root node
	Node* getRoot() {
		return this;
	}

	// Find node with the lowest value
	Node* findMin(Node* node) {

		Node* minPtr { node };

		if (minPtr != nullptr) {
			while (minPtr->left != nullptr) {
				minPtr = minPtr->left;
			}
		}

		std::cout << "Minimum is: " << minPtr->data << std::endl;
		return minPtr;
	}

	// Find node with the biggest value
	Node* findMax() {

		Node* maxPtr{ this };

		if (maxPtr != nullptr) {
			while (maxPtr->right != nullptr) {
				maxPtr = maxPtr->right;
			}
		}
		std::cout << "Maximum is: " << maxPtr->data << std::endl;
		return maxPtr;
	}

	// Find a specific node
	Node* find(int key) {
		Node* findPtr{ this };

		while (findPtr != nullptr) {
			if (key == findPtr->data) {
				std::cout << "Key " << key << " was found in tree as: " << findPtr->data << std::endl;
				return findPtr;
			}
			else if (key < findPtr->data) {
				if (findPtr->left != nullptr) {
					findPtr = findPtr->left;
				}
			}
			else if (key > findPtr->data) {
				if (findPtr->right != nullptr) {
					findPtr = findPtr->right;
				}
			}
		}
		std::cout << "Key " << key << " was not found in the tree." << std::endl;
		return nullptr;
	}


	// Here are tree traversal functions
	void inorder() {
		if (this != nullptr) {
			this->left->inorder();

			std::cout << this->data << std::endl;

			this->right->inorder();
		}
	}

	void preorder() {
		if (this != nullptr) {
			std::cout << this->data << std::endl;

			this->left->preorder();

			this->right->preorder();
		}
	}

	void postorder() {
		if (this != nullptr) {
			this->left->postorder();

			this->right->postorder();

			std::cout << this->data << std::endl;
		}
	}
};
