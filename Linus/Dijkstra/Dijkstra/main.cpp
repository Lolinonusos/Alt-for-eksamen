#include <iostream>
#include <queue>

#include "Graph.h"


template<class FirstVal, class SecondVal>
void swap(FirstVal *x, SecondVal *y) {
	FirstVal temp = *x;
	*x = *y;
	*y = temp;
}


// Currently only sort vectors
void selectionSort(std::vector<Vertex*> List) {

	int listSize = List.size();
	for (int i = 0; i < listSize; i++) {
		std::cout << List[i]->distFromStart << std::endl;
	}

	// Traverse the whole array
	for(int i = 0; i < listSize; i++) {
		int lowestValueIndex = i;
		int lowestValue = 999;
		
		// Traverse from last sorted position
		for (int j = i + 1; j < listSize; j++) {
			if (List[j]->distFromStart < List[lowestValueIndex]->distFromStart) {
				lowestValueIndex = j;
			}
		}

		// Will take in current indexes
		// where x is the array index poited on by the i for-loop
		// and y is the current lowest value found by the j for-loop
		// These two will be swapped using the swap function
		if (lowestValueIndex != i) {
			std::cout << "Swapping " << std::endl;
			swap(&List[lowestValueIndex], &List[i]);

		}
	}

	std::cout << "Sorted: " << std::endl;
	for (int i = 0; i < listSize; i++) {
		std::cout << List[i]->distFromStart << std::endl;
	}
}

// Setup connections between vertices
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

void fixedEdge(Vertex* From, Vertex* To) {

}

// Find if some vertices are not connected
void findClusters(Graph* graph) {
	
	std::vector<Vertex*> clusterArray;

	bool allConnected = false;
	
	clusterArray.push_back(graph->verts.at(0)); // will use vert at 0 because that will make it simple
		
	while (!allConnected) {
	
		//while (clusterArray.size() != graph->verts.size()){
			// Will use this to find if there are different clusters
			//int verticesFound = 1;

			// Find if we have separate clusters or not
		for (int i = 0; i < clusterArray.size(); i++) {
			int clArrayAt = clusterArray.at(i)->edgeList.size();
			for (int j = 0; j < clArrayAt; i++) {
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
			allConnected = true;
		}
	}
	// True if there are no separated clusters	
	return;
}


void dijkstra(Graph* graph) {

	Vertex* currentVert = graph->StartVert;

	std::vector<Vertex*> cheapest;

	while (!graph->EndVert->bVisited) {
		
		// Check currentvert for connected vertices
		for (int i = 0; i < currentVert->edgeList.size(); i++) {
			if (!currentVert->edgeList[i]->bVisited) {
		
				float distBetweenVert = currentVert->vertCost + currentVert->edgeList[i]->vertCost;

				float totalDist = distBetweenVert + currentVert->distFromStart;
				
				currentVert->edgeList[i]->prevVert = currentVert;

				if (totalDist < currentVert->edgeList[i]->distFromStart) {
					currentVert->edgeList[i]->distFromStart = totalDist;
				}
				cheapest.push_back(currentVert->edgeList[i]);
			}
		}
		// Sort 

		if (cheapest.at(0))
		{
			selectionSort(cheapest);
			currentVert = cheapest[0];
		}
		currentVert->bVisited = true;
	}
	// Print final path
	if (currentVert == graph->EndVert) {
		while (currentVert->prevVert != nullptr) {
			std::cout << "Help, am stuck" << std::endl;
			graph->finalPath.push_back(currentVert);
			currentVert = currentVert->prevVert;
		}
		std::cout << "The final path is:" << std::endl;
		for (int i = graph->finalPath.size(); i > 0; i--) {
			std::cout << graph->finalPath[i] << std::endl;
		}
	}
	
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
	fixedEdge(graph->verts[1], graph->verts[2]);
	findClusters(graph); // Fix this one later, focus on dijkstra now
	
	//dijkstra(graph);
	
	return 0;
}
