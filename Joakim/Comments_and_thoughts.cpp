//


//---------DIJKSTRA------------------
/*
 How do we check the linked nodes. 
Use Priority Queue for storing connecting nodes and their distance to then calculate which is shortest? After checking and discovering it is the shortest, move it to isNodeDiscovered?
Can we use Graph still? For having control of which nodes are connected to which?


DIjkstra goes through every single node to find its shortest path.

https://www.youtube.com/watch?v=FSm1zybd0Tk 
psuedo code:

Dijkstra(Graph graph, Node start)	// We take in a graph called graph and a node called start
{
	Map<Node, int> totalCosts = new Map<>();	// Basically connects each node with the shortest path cost, where the shortest path length from the start node to that node
	Map<Node, Node> prevNodes = new Map<>();	// Records which node we had to come from in order to create our shortest path
	MinPQ<Node> minPQ = new MinPQ<>();			// minimum priority queue
	Set<Node> visited = new Set<>();			// Set of nodes called visited. Set instead of list because of efficiency.

	totalCosts.put(start, 0);					// Set start node cost to 0
	minPQ.add(start);							// Add start node to minPQ

	for (Node node : graph.nodes())
	{
		if (node != start)						// For all nodes other than 'start'
		{
			totalCosts.put(node, INFINITY);		// Set all lengths to infinity at first, since any path we find must have length < INFINITY
		}
	}

	while (!minPQ.isEmpty())					// As long as minPQ is not empty		(the main loop of Dijkstra)
	{
		Node newSmallest = minPQ.deleteMin();	// Remove smallest item

		for (Node neighbour : newSmallest.neighbours())		// Check all the neighbours of the element we just removed
		{
			if (!visited.contains(neighbour))	// Check that it is not visited
			{
				int altPath = totalCosts.get(newSmallest) + distance(newSmallest, neighbour);	// Find shortest known path from start node to that neighbour node. 
																								   This is done by getting the shortest known cost from our start node to the
																								   node that we just removed + the shortest known cost from the node that we just removed
																								   to its neighbour
				if (altPath < totalCosts.get(neighbour))	// We now check if the path that we just found is shorter (or less expensive cost) than the existing path for that neighbour
				{
					totalCosts.put(neighbour, altPath);		// Update path length for neighbour with the new shortest cost or length
					prevNodes.put(neighbour, newSmallest);	// Update previous node to the node we just removed

					minPQ.decreasePriority(neighbour, altPath);		// Update priority in minPQ. We decrease the priority in minPQ of that neighbour, which now has a priority equal to
																	   the length or the cost of this new path called altPaths.
				}
			}
		}
	}

	List<Object> results = new List<>();
	results.add(totalCosts); results.add(prevNodes);
	return results;											// Results contains: totalCosts=map of each node to its shortest path lenngth from start node.
															   and prevNodes=map of each node to node it came from (parent).
}

*/