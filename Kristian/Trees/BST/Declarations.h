#pragma once

#include <iostream>

class BaseTree {
public:

	int value;

	BaseTree* Right;
	BaseTree* Left;

	BaseTree() {
		Right = nullptr;
		Left = nullptr;
	}

	BaseTree* CreateNodes(int value);
};

BaseTree* BaseTree::CreateNodes(int value) {
	BaseTree* NewNode = new BaseTree();

	if (NewNode)
	{
		NewNode->Left = nullptr;
		NewNode->Right = nullptr;

		NewNode->value = value;
	}
	return NewNode;

}