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
	void insertIntoTree(int tall) {

		// very kul code. Does not not do duplicates :^)
		// Thank Mathis
		if (tall < this->data) {
			if (this->left == nullptr) {
				this->left = new Node(tall);
			}
			else {
				this->left->insertIntoTree(tall);
			}
		}
		else if (tall > this->data) {
			if (this->right == nullptr) {
				this->right = new Node(tall);
			}
			else {
				this->right->insertIntoTree(tall);
			}
		}
	}

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
		secondToLast->left = nullptr;
		delete toDelete;
	}

	// Removes a value from the tree
	Node* remove(int tall) {
		
		// End early if the tree does not exist
		if (this == nullptr) {
			return this;
		}

		// Find the node to be removed
		if (tall < this->data) {
			this->left = this->left->remove(tall);
		}
		else if (tall > this->data) {
			this->right = this->right->remove(tall);
		}
		else {
			// Node is found and has only one or no child nodes
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
			Node* tmp = findMin(this->right);
		
			this->data = tmp->data;

			this->right->remove(tmp->data);
		}
		return this;
	}


	// Functions from here are used to find things in the tree
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