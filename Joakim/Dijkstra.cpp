#include <iostream>

// Source: https://www.youtube.com/watch?v=a1Z1GmKzcPs&ab_channel=FriendlyDeveloper		
// Source code: https://gist.github.com/nateshmbhat/1a79daa00a148e44ad79c3e338977440#file-dijkstra_algorithm-cpp

using namespace std;

/*

// Cost = 999 = Infinity
#define INF 999

// V = Verticies	||		src = Source vertex		||  	 cost = cost matrix 100x100 that represents our graph
int V, src, cost[100][100];

// Distance array
int dist[100]; 

// Check that all the nodes are not yet visited
bool visited[100] = { 0 };

// To keep track of the parent node
int parent[100];


// Function for initializing the distance values
void init()
{
	// For each vertex in V, initialize the distance to infinity
	for (int i = 0; i < V; i++)
	{
		parent[i] = i;
		dist[i] = INF;
	}


	// Source node gets a distance of zero
	dist[src] = 0;
}

// Returns the nearest unvisited node
int getNearestNode()
{
	int minValue = INF;
	int minValueNode = 0;

	for (int i = 0; i < V; i++)
	{
		// Check if node i is not visited and its distance is less than current minimum value, 
		// we then update minimum value to the lesser distance and the corresponding minimum node to the i node
20		if (!visited[i] && dist[i] < minValue)
		{
			minValue = dist[i];
			minValueNode = i;
		}
	}

	return minValueNode;
}

// Runs until all nodes have been visited
void dijkstra()
{
	for (int i = 0; i < V; i++) // Can optimize by running int i = 0; i < V-1; i++
	{
		// Get nearest unvisited node
		int nearest = getNearestNode();

		// mark the node as visited
		visited[nearest] = true;

		// Update distances of all adjacent nodes
		for (int adj = 0; adj < V; adj++)
		{
			// Check if the adj is adjacent to the nearest node
			if (cost[nearest][adj] != INF && dist[adj] > dist[nearest] + cost[nearest][adj])
			{
				// Update adjacent node to the new node
				dist[adj] = dist[nearest] + cost[nearest][adj];

				// Update parent node
				parent[adj] = nearest;
			}
		}
	}
}

// Display of all the nodes and their least-cost with respect to the source node, and their corresponding paths.
void display()
{
	cout << "Node: \t\t\tCost : \t\t\tPath";

	// Look at all the nodes and print their distances and node, and its corresponding distance and its path
	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t\t" << dist[i] << "\t\t\t" << " ";

		cout << i << " ";
		int parnode = parent[i];

		while (parnode != src)
		{
			cout << " <-- " << parnode << " ";
			parnode = parent[parnode];
		}
		cout << endl;
	}
}

int main()
{
	cout << "Number of verticies: ";
	cin >> V;

	cout << "Enter cost matrix: " << endl;

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cin >> cost[i][j];
		}
	}

	cout << "src node: ";
	cin >> src;

	init();

	dijkstra();

	display();

	return 0;
}

*/