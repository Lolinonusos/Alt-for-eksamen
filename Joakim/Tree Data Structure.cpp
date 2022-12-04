#include <iostream>

using namespace std;

// Explanation of trees ----------------------------------------------------------------------------------------------------
// Video: https://www.youtube.com/watch?v=UHxtjVsOTHc

/*
// Can only be one root node (head?)
// Can be multiple leaf nodes, what makes them leaf nodes is that they do not have children.

// A normal tree can look like this
//									P
//								/	|	\
//							   /	|	 \
//							  L		L	  L
// (I used P and L just for visuals, they are simply just nodes.)
// Parents can have more or less children than visualized.
// 
// 
// Example of Binary Tree
//									 Node
//								/			\
//							   /			 \
//							 Node			 Node
//							 /				/	 \
//							/			   /	  \
//						 Node			Node	  Node
// 
// Like a normal tree it defines a parent child relationship.
// Each parent can not have more than 2 child nodes. It can have zero, one or two, but not more.
// 
// 
// Binary Search Tree (BST)
// 
// Exactly the same as a Binary Tree, except that its data is organized in a very spesific way. 
// So the values of nodes are organized in a very specific way.
// 
// 									 30
//									/	\
//								   /	 \
//								  20	 50
//								 /		/	\
//								/	   /     \
//							   15	  40	 55
// 
// Here root node has the value 30. 
// The rule is that left childs should have lower value than their parent, while the right child should have more.
// 
// 
// Coding part -------------------------------------------------------------------------------------------------------------------------------------
// 
// struct Node -------------------
// Each Node has 3 parts. 
//		1. Data
//		2. Left child pointer
//		3. Right child pointer
// 
// createNode --------------------
// Create a new node and return the reference to that node, which we need if we want to add left/right child to that node.
// 4 steps inside this function.
//		1. Create a new node
//		2. Set data for that node
//		3. Take care of left and right child nodes, which initially will be null
//		4. Return a reference to the node
//

struct Node
{
	int data;
	Node* leftChild;
	Node* rightChild;
};

Node* createNode(int data)
{
	Node* newNode = new Node(); // Step 1.

	newNode->data = data;		// Step 2.

	newNode->leftChild = newNode->rightChild = nullptr; // Step 3.

	return newNode;				// Step 4.
}

void recreateSimpleTree()
{
// 									  1
//									/	\
//								   /	 \
//								  2		  3
//								 /		
//								/	   
//							   4

	Node* root = createNode(1); // 1, because the drawing says so :P

	root->leftChild = createNode(2);
	root->rightChild = createNode(3);

	root->leftChild->leftChild = createNode(4);

	// TAdaaaaaa
}

void recreateMoreAdvancedTree()
{
// 									    1				Level 1
//									/		\
//								   /		 \
//								  2			  3			Level 2
//								 /\			/	\
//								/  \	   /     \
//							   4	5	  6		  7		Level 3
//								   /			 /
//								  /		    	/
//								 9			   15		Level 4

// (Why we suddenly abandonded the rule about lower value is leftChild and higher value is rightChild, I have no idea)
//

	// Level 1
	Node* root = createNode(1);

	// Level 2
	root->leftChild = createNode(2);
	root->rightChild = createNode(3);

	// Level 3
	root->leftChild->leftChild = createNode(4);
	root->leftChild->rightChild = createNode(5);
	root->rightChild->leftChild = createNode(6);
	root->rightChild->rightChild = createNode(7);

	// Level 4
	root->leftChild->rightChild->leftChild = createNode(9);
	root->rightChild->rightChild->leftChild = createNode(15);

}


// Tree Traversal ---------------------------------------------------------------------------------------------------
// Tree Traversal Algorithms (BFS, DFS, Preorder, Inorder, Postorder)
// Video: https://www.youtube.com/watch?v=_IhTp8q0Mm0


// Why do we need to Traverse a tree?
//		It is the only way to access the data that is stored inside (non leaf?) nodes.
//		Two sorts of algorithms to traverse a tree: BFS and DFS.
//				BFS: Breadth First Search. Will first search the width of the tree.
//				DFS: Depth First Search. Will first search the depth of the tree.
// 
// 
// BFS:
// 									    1				Level 1
//									/	|	\
//								   /	|	 \
//								  2		3	  4			Level 2
//								 /\			/	\
//								/  \	   /     \
//							   5	6	  7		  8		Level 3
//							  /	\		  | \
//							 /	 \	      |  \
//							9	 10		  11  12		Level 4
// 
// Breadth First Search will first visit node 1 on Level 1.
// Then it will go down to Level 2, visit all the nodes (2, 3, 4).
// After that it will go down to Level 3 and visit all the nodes there (5, 6, 7, 8).
// After that it goes down to Level 4 and visits all the nodes there (9, 10, 11, 12).
// 
// 
// DFS:
// 									    1				Level 1
//									/	|	\
//								   /	|	 \
//								  2		7	  8			Level 2
//								 /\			/	\
//								/  \	   /     \
//							   3	6	  9		  12	Level 3
//							  /	\		  | \
//							 /	 \	      |  \
//							4	  5		  10  11		Level 4
// 
// There are 3 depth-first search algorithms.
//		1. preorder (data, left, right)		// First we manipulate the data, then we go to the left child, then we go to the right child.
//		2. inorder (left, data, right)		// First we go to the left child, then we manipulate the data, then we go to the right child.
//		3. postorder (left, right, data)	// First we go to the left child, then we go to the right child, then we manipulate the data.
// 
// Preorder algorithm --------------------
// 
// 									    1				
//									/		\
//								   /		 \
//								  2			  3			
//								 /\			/	\
//								/  \	   /     \
//							   4	5	  6		  7		
//								   /			 /
//								  /		    	/
//								 9			   15		
// 
// Start from root. Manipulate data (1). Then go to left child. This restarts the algorithm.
// Manipulate the data (2). Go to the left child. Restart algorithm.
// Manipulate the data (4). Go to the left child. But this node does not have a left child. Then we go to right child. But there is no right child either.
// We then go back to the parent node of that node and check its right node. Restart algorithm.
// Manipulate the data (5). Go to the left child. Restart algorithm.
// Manipulate data (9). Visit left child, none found. Visit right child, none found. 
// Go back to parent node. Check right child, none found. Go to parent node.
// Both right and left child visited, so we go to parent node. We are now back at root.
// Roots left child has been visited so we visit the right child.
// Manipulate the data (3). Go to the left child. Restart algorithm.
// Manipulate the data (6). Check left child, none found. Check right child, none found. 
// Go back to parent node. Check right child, found. Restart algorithm.
// Manipulate the data (7). Visit left child. Restart algorithm.
// Manipulate the data (15). Check left child, none found. Check right child, none found.
// Go back to parent node. Check right child, none found. Go to parent node.
// Both right and left child visited, so we go to parent node. We are now back at root.
// Roots left and right child have been visited, the algorithm is therefore finished.
// 
// Visiting order: 1, 2, 4, 5, 9, 3, 6, 7, 15

void preorderPrintTree(Node* root)
{
	if (root == nullptr) return;

	cout << root->data << endl;
	preorderPrintTree(root->leftChild);
	preorderPrintTree(root->rightChild);
}


// Inorder algorithm --------------------
//
// 									    1				
//									/		\
//								   /		 \
//								  2			  3			
//								 /\			/	\
//								/  \	   /     \
//							   4	5	  6		  7		
//								   /			 /
//								  /		    	/
//								 9			   15		
// 
// inorder (left, data, right).
// 
// Start at the root node. Visit left child. Restart algorithm.
// Visit left child, none found. Manipulate the data (4). Visit right child, none found.
// Go back to parent node. Left child visited. Manipulate the data (2). Visit right child. Restart algo.
// Visit left child. Restart algo.
// Visit left child, none found. Manipulate the data (9). Visit right child, none found.
// Go back to parent node. Manipulate the data (5). Visit right child, none found.
// Go back to parent node. Both children found. 
// Go back to parent node. Manipulate the data (1). Visit right child. Restart algo.
// Visit left child. Restart algo.
// Visit left child, none found. Manipulate the data (6). Visit right child, none found.
// Go back to parent node. Manipulate the data (3). Visit right child. Restart algo.
// Visit left child. Restart algo.
// Visit left child, none found. Manipulate the data (15). Visit right child, none found.
// Go back to parent node. Manipulate the data (7). Visit right child, none found.
// Go back to parent node. Both children found.
// Go back to parent node. Both children found.
// Current node is root. Algorithm is done.
// 
// Printing order: 4, 2, 9, 5, 1, 6, 3, 15, 7
//

void inorderPrintTree(Node* root)
{
	if (root == nullptr) return;

	inorderPrintTree(root->leftChild);
	cout << root->data << endl;
	inorderPrintTree(root->rightChild);
}


// Postorder --------------------
//
// 									    1				
//									/		\
//								   /		 \
//								  2			  3			
//								 /\			/	\
//								/  \	   /     \
//							   4	5	  6		  7		
//								   /			 /
//								  /		    	/
//								 9			   15		
// 
// postorder (left, right, data)
// 
// Start at the root node. Visit left child. Restart algo.
// Visit left child. Restart algorithm
// Visit left child, not found. Visit right child, not found. Manipulate the data (4).
// Go back to parent node. Visit right child. Restart algo.
// Visit left child. Restart algo.
// Visit left child, not found. Visit right child, not found. Manipulate the data (9).
// Go back to parent node. Visit right child, not found. Manipulate the data (5).
// Go back to parent node. Both children found. Manipulate the data (2). 
// Go back to parent node. Visit right child. Restart algo.
// Visit left child. Restart algo.
// Visit left child, not found. Visit right child, not found. Manipulate the data (6).
// Go back to parent node. Visit right child. Restart algo.
// Visit left child. Restart algo.
// Visit left child, not found. Visit right child, not found. Manipulate the data (15).
// Go back to parent node. Visit right child, not found. Manipulate the data (7).
// Go back to parent node. Both children visited. Manipulate the data (3).
// Go back to parent node. Both children visited. Manipulate the data (1).
// Current node is root. Algorithm is done.
// 
// Predicted printing order: 4, 9, 5, 2, 6, 15, 7, 3, 1
//

void postorderPrintTree(Node* root)
{
	if (root == nullptr) return;

	postorderPrintTree(root->leftChild); 
	postorderPrintTree(root->rightChild); 
	cout << root->data << endl;
}



void treeExample()
{
	Node* root = createNode(1);
	root->leftChild = createNode(2);
	root->leftChild->leftChild = createNode(4);
	root->leftChild->rightChild = createNode(5);
	root->leftChild->rightChild->leftChild = createNode(9);

	root->rightChild = createNode(3);
	root->rightChild->leftChild = createNode(6);
	root->rightChild->rightChild = createNode(7);
	root->rightChild->rightChild->leftChild = createNode(15);

	cout << "This is preorder:" << endl;
	preorderPrintTree(root);
	cout << endl << endl;

	cout << "This is inorder:" << endl;
	inorderPrintTree(root);
	cout << endl << endl;

	cout << "This is postorder: " << endl;
	postorderPrintTree(root);
	cout << endl << endl;
}

int main()
{
	treeExample();


	
	return 0;
}

*/