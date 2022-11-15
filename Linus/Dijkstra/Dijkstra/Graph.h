#pragma once
#include <vector>


class Vertex; // forward declaration


// An Edge connects two Vertices
// Weight can be seen as the distance between two Vertices
class Edge {
public:

	// Pointers defining which vertices are connected
	Vertex* V; // Start vertex
	Vertex* W; // end vertex

	// Cost of travelling between said vertices
	int weigth = 0;

	// Create an edge between two vertices
	Edge(Vertex* v, Vertex* w) {
		V = v;
		W = w;
		
	}
};


// Vertex is a point.
// It can connected to another Vertex by an Edge
class Vertex {
public:

	
	std::vector<Edge> edgeList;

	bool visited = false;
	
};


// Graph is the map, a collection of Vertices and Edges
class Graph {
public:
	std::vector<Vertex*> verts;
	
	int distance = 0;

	Vertex* previous;
	
	Graph() {
		distance = 0;
		previous = nullptr;
	}

	~Graph() {}

private:
	
};


// Path is the item that will be stored in a priority queue.
// The path is a sequence of Vertices, storing the total distance between them in each path item
class Path {
public:
	std::vector<Edge> edges;

	int destination; // Vertex W
	
	int pathCost() {
		
	}



	
	float GetCost() const {
		float cost{};
		for (const Edge& e : edges) {
			cost += e.weigth;
		}
		return cost;
	}
	bool operator < (const Path& otherPath) const {
		return GetCost() < otherPath.GetCost();
	}
};
