#include <iostream>
#include <queue>

#include "Graph.h"

void edgeSetup(Graph* graph) {
	
	for (int i = 0; i < graph->verts.size(); i++) {

		int GiveEdges = 30;

		for (int j = 0; j < GiveEdges; i++) {
			
			

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
