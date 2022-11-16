#pragma once
#include <list>
#include <vector>


class Vertex; // forward declaration


// An Edge connects two Vertices
// Weight can be seen as the distance between two Vertices
class Edge {
public:

	int dest; // index of destination vertex. Only this is needed as the source vertex is implicit
	int weight; // Distance of this edge

	Edge(int d, int w) {
		dest = d;
		weight = w;
	}
};


// Vertex is a point.
// It can connected to another Vertex by an Edge
template <class Data>
class Vertex {
public:

	Data data; // This could be whatever. Maybe a name or something, but I do not care.
	std::vector<Edge> edgeList; // This is the adjacency list

	std::list<Edge> adj;
	
	Vertex(Data input) {
		data = input;
		
	}

	
	bool visited = false;
	
};


// Graph is the map, a collection of Vertices and Edges
template <class Data>
class Graph {
public:
	
	std::vector<Vertex> verts;
	
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
			cost += e.weight;
		}
		return cost;
	}
	bool operator < (const Path& otherPath) const {
		return GetCost() < otherPath.GetCost();
	}
};
