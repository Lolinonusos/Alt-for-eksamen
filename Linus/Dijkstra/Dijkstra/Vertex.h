#pragma once

#define INF 9999999

// Vertex is a point.
// It can be connected to another Vertex by an Edge
class Vertex {
public:

	int vertCost; // Added to distance if MeisMann wants me to
	int distFromStart = INF; // Cost for travelling to this vertex from start
	int index; // This could be whatever. Maybe a name or something, but I do not care.
	bool bVisited = false; // Check for when running path finding algorithms

	// This is the adjacency list
	// Keeps track of which nodes are connected
	std::vector<class Edge*> edgeList;

	//  
	

	Vertex(int input) {
		vertCost = rand() % 10 + 1;
		index = input;
	}
};