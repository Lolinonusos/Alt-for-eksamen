#pragma once

class Node {
public:

	int data{};
	Node* next{ nullptr };

	Node(int input) {
		data = input;
	}
};