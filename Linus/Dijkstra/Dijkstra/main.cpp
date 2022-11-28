#include <iostream>
#include <queue>

#include "Graph.h"

void swap(Graph* graph, int x, int y) {
	int temp = x;
	graph->verts[x]->data = graph->verts[y]->data;
	graph->verts[y]->data = graph->verts[temp]->data;
}

void selectionSort(Graph* graph) {

	// Traverse the whole array
	for(int i = 0; i < 10; i++) {
		int lowestValueIndex = i;
		int lowestValue = 999;
		
		// Traverse from last sorted position
		for (int j = i; j < 10; j++) {
			if (lowestValue > graph->verts[i]->data) {
				lowestValue = graph->verts[i]->data;
			}
		}
		// Will take in current indexes
		// where x is the array index poited on by the i for-loop
		// and y is the current lowest value found by the j for-loop
		// These two will be swapped using the swap function
		swap(graph, i, lowestValueIndex);
	}
}

void edgeSetup(Graph* graph) {

	int vertArrSize = graph->verts.size();
	
	for (int i = 0; i < vertArrSize; i++) {

		// How many egdes will be given to a vertex
		int GiveEdges = rand() % 5 + 1; // Connect to min 1, max 5 vertices
		
		for (int j = 0; j < GiveEdges; j++) {

			// Pick a randon vertex to connect to
			int RandVert = rand() % vertArrSize;

			// Do not connect a vertex to iself
			if (RandVert != i) {
				graph->verts[i]->edgeList.push_back(graph->verts[RandVert]); // Connect vertices
				graph->verts[RandVert]->edgeList.push_back(graph->verts[i]); // Reverse connection
				std::cout << "Connected vertices " << i << " and " << RandVert << std::endl;
			}

		}
	}
}

// Find if some vertices are not connected
bool findClusters(Graph* graph) {
	
	std::vector<Vertex*> clusterArray;

	bool allConnected = false;
	
	clusterArray.push_back(graph->verts.at(0)); // will use vert at 0 because that will make it simple
		
	while (!allConnected) {
	
		//while (clusterArray.size() != graph->verts.size()){
			// Will use this to find if there are different clusters
			//int verticesFound = 1;

			// Find if we have separate clusters or not
			for (int i = 0; i < clusterArray.size(); i++) {
				for (int j = 0; j < clusterArray.at(i)->edgeList.size(); i++) {
					if (clusterArray[i]->edgeList[j] == nullptr) {
						clusterArray.push_back(clusterArray[i]->edgeList[j]);
					}
				}
			}
		//}

		// If clusterArray is smaller than verts, that means that there are separate
		// clusters of vertices. During this step we will connect the clusters.
		if(clusterArray.size() != graph->verts.size()) {
			bool findDisconnected = false;
			while (!findDisconnected) {

				for (int i = 0; i < graph->verts.size(); i++) {
					for(int j = i; j < graph->verts.size(); j++) {
						
						if (clusterArray[i] == graph->verts[j]) {
							findDisconnected = false;
							break;
						}
						else {
							
						}
					}
				}
			}
		}
		else {
			return true;
		}
	}
	// True if there are no separated clusters	
	return true;
}

void dijkstra(Graph* graph) {

	Vertex* currentVert = graph->StartVert;

	while (!graph->EndVert->bVisited) {

		// Check currentvert for connected vertices
		for (int i = 0; i < currentVert->edgeList.size(); i++) {
			if (!currentVert->edgeList[i]->bVisited) {
				
			
			}
		}

	}
	// Print final path
	
	//std::priority_queue<int> pq;
}



int main() {
	// Set seed
	srand(time(0));

	// Amount of vertices to create
	int VertsToCreate = 10;
	
	Graph* graph {new Graph(VertsToCreate)}; // Faster than writing =

	//graph = new Graph<int>;
   	
	edgeSetup(graph); // Working as intented
	findClusters(graph);
	
	dijkstra(graph);
	
	return 0;
}
