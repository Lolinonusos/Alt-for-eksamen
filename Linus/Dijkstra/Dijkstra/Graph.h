#pragma once
#include "Vertex.h"

#include <list>
#include <vector>




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
		StartVert->distFromStart = 0;
		StartVert->bVisited = true;
		
		EndVert = verts.at(VertsToCreate - 1);
		EndVert->distFromStart = 0;
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
