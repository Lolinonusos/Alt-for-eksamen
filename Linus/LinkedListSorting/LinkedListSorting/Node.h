#pragma once

class Node {

	int data{};

	Node* next{ nullptr };

	Node(int input) {
		data = input;
	}
};