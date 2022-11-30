#pragma once
#include <list>
#include <vector>
#define INF 9999999

// An Edge connects two Vertices
// Weight can be seen as the distance between two Vertices
// class Edge {
// public:
//
// 	int dest; // index of destination vertex. Only this is needed as the source vertex is implicit
// 	int weight; // Distance of this edge
//
// 	Edge(int d, int w) {
// 		dest = d;
// 		weight = w;
// 	}
// };


// Vertex is a point.
// It can connected to another Vertex by an Edge
class Vertex {
public:

	int distance = INF; // Cost for travelling to this vertex from start
	int data; // This could be whatever. Maybe a name or something, but I do not care.
	bool bVisited = false;
	
	// This is the adjacency list
	// Keeps track of which nodes are connected
	std::vector<Vertex*> edgeList;

	//  
	Vertex* prevVert = nullptr;
	
	Vertex(int input) {
		data = input;
	}
};


// Graph is the map, a collection of Vertices and Edges
class Graph {
public:

	// Keeps track of current total number of vertices
	std::vector<Vertex*> verts;

	Vertex* StartVert;
	Vertex* EndVert;
	Graph();
	Graph(int VertsToCreate) {

		// Create all the vertices
		for (int i = 0; i < VertsToCreate; i++) {
			Vertex* newVert = new Vertex(i);
			verts.push_back(newVert);
		}

		// Correct the starting values for start and end vertices
		StartVert = verts.at(0);
		StartVert->distance = 0;
		StartVert->bVisited = true;
		
		EndVert = verts.at(VertsToCreate - 1);
		EndVert->distance = 0;
	}

	std::vector<Vertex*> finalPath;
	
	~Graph() {}

private:
	
};



// Path is the item that will be stored in a priority queue.
// The path is a sequence of Vertices, storing the total distance between them in each path item
class Path {
public:
	//std::vector<Edge> edges;

	int destination; // Vertex W
	
	int pathCost() {
		
	}



	
	// float GetCost() const {
	// 	float cost{};
	// 	//for (const Edge& e : edges) {
	// 		cost += e.weight;
	// 	}
	// 	return cost;
	// }
	// bool operator < (const Path& otherPath) const {
	// 	return GetCost() < otherPath.GetCost();
	// }
};
