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
		if (tall > this->data) {
			if (this->right == nullptr) {
				this->right = new Node(tall);
			}
			else {
				this->right->insertIntoTree(tall);
			}
		}
		else if (tall < this->data) {
			if (this->left == nullptr) {
				this->left = new Node(tall);

			}
			else {
				this->left->insertIntoTree(tall);
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
	void remove(int tall) {
		
		// End early if the chosen node is the root
		if (tall == this->data) {
			return;
		}

		Node* toDelete{ this };


		
		if (tall < toDelete->right) {
			toDelete->right = remove(tall);
		}
		else if (tall > toDelete->left) {
			findPtr = findPtr->right;
		}
	
	}


	// Functions from here are used to find things in the tree
	Node* getRoot() {
		return this;
	}

	// Find node with the lowest value
	Node* findMin() {

		Node* minPtr { this };

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


	void displayTree() {

	}



};