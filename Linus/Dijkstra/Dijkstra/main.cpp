#include <iostream>
#include <queue>

#include "Graph.h"

void edgeSetup(Graph* graph) {
	
	for (int i = 0; i < graph->verts.size(); i++) {

		int GiveEdges = 30;
		
		for (int j = 0; j < GiveEdges; i++) {
			int RandVert = 4;
			
			graph->verts[i]->edgeList.push_back(graph->verts[RandVert]); // Connect vertices
			graph->verts[RandVert]->edgeList.push_back(graph->verts[i]); // Reverse connection
		}
	}
}


void dijkstra() {

	

	std::priority_queue<int> pq;
}



int main() {
	int VertsToCreate = 10;
   	
	
	Graph* graph {new Graph(VertsToCreate)}; // Faster than writing =

	//graph = new Graph<int>;
   	
	edgeSetup(graph);
   	
	return 0;
}
