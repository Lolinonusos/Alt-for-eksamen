#include <iostream>
#include <stack>
#include <set>

using namespace std;

// https://www.geeksforgeeks.org/a-search-algorithm/

// Algorithm
// We create two lists - Open List and Closed List (just like Dijkstra)

/* 

// 1. Initialize the open list
// 2. Initialize the closed list, put the starting node on the open list 
//    (you can leave its f at zero)
// 3. While the open list is not empty:
//		a) find the node with the least f on the open list, call it "q".
//		b) pop q off the open list
//		c) generate q's 8 successors and set their parents to q
//		d) for each successor:
//			i) if successor is the goal, stop search
//			ii) else, compute both g and h for successor
//				successor.g = q.g + distance between successor and q
//				successor.h = distance from goal to successor (Manhattan, Diagonal, Euclidean)
//				successor.f = successor.g + successor.h
//			iii) if a node with the same position as successor is in the OPEN
//				 list which has a lower f than successor, skip this successor
//			iv) if a node with the same position as successor is in the OPEN
//				list which has a lower f than successor, skip this successor
//				otherwise, add the node to the open list
//			end (for loop)
//		e) push q on the closed list
//		end (while loop)
// 
// Implementation: 
// We can use any data structure to implement open list and closed list but for 
// best performance, we use a set data structure of C++ STL(implemented as 
// Red-Black Tree) and a boolean hash table for a closed list.
// The implementations are similar to Dijkstra’s algorithm.If we use a Fibonacci 
// heap to implement the open list instead of a binary heap / self - balancing 
// tree, then the performance will become better(as Fibonacci heap takes O(1) 
// average time to insert into open listand to decrease key)
//
// Also to reduce the time taken to calculate g, we will use dynamic programming.
//



#define ROW 9
#define COL 10

// Creating a shortcut for int, int pair type
typedef pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
typedef pair<double, pair<int, int>> pPair;

// A structure to hold the necessary parameters
struct cell
{
	// Row and Column index of its parent
	// Note that 0 <= i <= ROW - 1 & 0 <= j <= COL - 1
	int parent_i, parent_j;
	// f = g + h;
	double f, g, h;
};

// A utility function to check wether given cell (row, col) is a valid cell or not
bool isValid(int row, int col)
{
	// Returns true if row number and column number is in range
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// A utility function to check wether the given cell is blocked or not
bool isUnBlocked(int grid[][COL], int row, int col)
{
	// Returns true if the cell is not blocked else false
	if (grid[row][col] == 1)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

// A utility function to check wether destination cell has been reached or not
bool isDestination(int row, int col, Pair dest)
{
	if (row == dest.first && col == dest.second)
		return (true);
	else
		return (false);
}

// A utility function to calculate the 'h' heuristics
double calculateHValue(int row, int col, Pair dest)
{
	// Return using the distance formula
	return ((double)sqrt(
		(row - dest.first) * (row - dest.first)
		+ (col - dest.second) * (col - dest.second)));
}

// A utility function to trace the path from source to destination
void tracePath(cell cellDetails[][COL], Pair dest)
{
	cout << "\nThe Path is ";

	int row = dest.first;
	int col = dest.second;

	stack<Pair> Path;

	while (!(cellDetails[row][col].parent_i == row
		&& cellDetails[row][col].parent_j == col))
	{
		Path.push(make_pair(row, col));

		int temp_row = cellDetails[row][col].parent_i;
		int temp_col = cellDetails[row][col].parent_j;

		row = temp_row;
		col = temp_col;
	}

	Path.push(make_pair(row, col));

	while (!Path.empty())
	{
		pair<int, int> p = Path.top();
		Path.pop();
		printf("-> (%d,%d) ", p.first, p.second);
		//cout << "-> " << "(" << p.first << p.second << " ";	// Is this the same?
	}

	return;
}

// A function to find the shortest path between a given source cell to a destination
// cell according to A* Search Algorithm
void aStarSearch(int grid[][COL], Pair src, Pair dest)
{
	// If the source is out of range
	if (isValid(src.first, src.second) == false)
	{
		cout << "Source is invalid" << endl;
		return;
	}

	// If the destination is out of range
	if (isValid(dest.first, dest.second) == false)
	{
		cout << "Destination is invalid" << endl;
		return;
	}

	// Either the source or the destination is blocked
	if (isUnBlocked(grid, src.first, src.second) == false
		|| isUnBlocked(grid, dest.first, dest.second) == false)
	{
		cout << "Source or the destination is blocked" << endl;
		return;
	}

	// If the destination cell is the same as source cell
	if (isDestination(src.first, src.second, dest) == true)
	{
		cout << "We are already at the destination" << endl;
		return;
	}

	// Create a closed list and initialise it to false which means that no cell
	// has been included yet this closed list is implemented as a boolean 2D array
	bool closedList[ROW][COL];
	memset(closedList, false, sizeof(closedList));

	// Declare a 2D array of structure to hold the details of that cell
	cell cellDetails[ROW][COL];

	int i, j;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			cellDetails[i][j].f = FLT_MAX;
			cellDetails[i][j].g = FLT_MAX;
			cellDetails[i][j].h = FLT_MAX;
			cellDetails[i][j].parent_i = -1;
			cellDetails[i][j].parent_j = -1;
		}
	}

	// Initialising the parameters of the starting node
	i = src.first, j = src.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent_i = i;
	cellDetails[i][j].parent_j = j;

	//Create an open list having information as-
	// <f, <i, j>>
	//	where f = g + h,
	//		and i, j are the rowand column index of that cell
	//		Note that 0 <= i <= ROW - 1 & 0 <= j <= COL - 1
	//		This open list is implemented as a set of pair of pair.

	set<pPair> openList;

	// Put the starting cell on the open list and set its 'f' as 0
	openList.insert(make_pair(0.0, make_pair(i, j)));

	// We set this boolean value as false as initially the destination is not
	// reached
	bool foundDest = false;

	while (!openList.empty())
	{
		pPair p = *openList.begin();

		// Remove this vertex from the open list
		openList.erase(openList.begin());

		// Add this vertex to the closed list
		i = p.second.first;
		j = p.second.second;
		closedList[i][j] = true;

		//Generating all the 8 successor of this cell
//
//			N.W   N   N.E
//			\   |   /
//			\  |  /
//			W----Cell----E
//			/ | \
//			/   |  \
//			S.W    S   S.E
//
//			Cell-- > Popped Cell(i, j)
//			N-- > North(i - 1, j)
//			S-- > South(i + 1, j)
//			E-- > East(i, j + 1)
//			W-- > West(i, j - 1)
//			N.E-- > North - East(i - 1, j + 1)
//			N.W-- > North - West(i - 1, j - 1)
//			S.E-- > South - East(i + 1, j + 1)
//			S.W-- > South - West(i + 1, j - 1)

		// To store the 'g', 'h', and 'f' of the 8 successors
		double gNew, hNew, fNew;

		//----------- 1st Successor (North) ------------

		// Only process this cell if this is a valid one
		if (isValid(i - 1, j) == true) 
		{
			// If the destination cell is the same as the current successor
			if (isDestination(i - 1, j, dest) == true) 
			{
				// Set the Parent of the destination cell
				cellDetails[i - 1][j].parent_i = i;
				cellDetails[i - 1][j].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			// If the successor is already on the closed list or if it is blocked
			// then ignore it. Else do the following
			else if (closedList[i - 1][j] == false 
				&& isUnBlocked(grid, i - 1, j) == true)
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i - 1, j, dest); 
				fNew = gNew + hNew;

				// If it isnt on the open list, add it to the open list.
				// Make the current square the parent of this square. Record
				// the f, g and h costs of the square cell
				//					OR
				// If it is on the open list already, check to see if this 
				// path to that square is better, using 'f' cost as the measure.

				if (cellDetails[i - 1][j].f == FLT_MAX
					|| cellDetails[i - 1][j].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i - 1, j)));

					// Update the details of this cell
					cellDetails[i - 1][j].f = fNew;
					cellDetails[i - 1][j].g = gNew;
					cellDetails[i - 1][j].h = hNew;
					cellDetails[i - 1][j].parent_i = i;
					cellDetails[i - 1][j].parent_j = j;
				}
			}
		}

		//----------- 2nd Successor (South) ------------

		// Only process this cell if this is a valid one
		if (isValid(i + 1, j) == true)
		{
			// If the destination cell is the same as the current successor
			if (isDestination(i + 1, j, dest) == true)
			{
				// Set the parent of the destination cell
				cellDetails[i + 1][j].parent_i = i;
				cellDetails[i + 1][j].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			// If the successor is already on the closed list or if it is blocked
			// then ignore it. Else do the following
			else if (closedList[i + 1][j] == false
				&& isUnBlocked(grid, i + 1, j) == true)
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i + 1, j, dest);
				fNew = gNew + hNew;

				// If it isnt on the open list, add it to the open list.
// Make the current square the parent of this square. 
// Record the f, g, and h costs of the square cell
//						OR
// If it is on the open list already, check to see if this
// path to that square is better, using 'f' cost as the measure.
if (cellDetails[i + 1][j].f == FLT_MAX
	|| cellDetails[i + 1][j].f > fNew)
{
	openList.insert(make_pair(fNew, make_pair(i + 1, j)));

	// Update the details of this cell
	cellDetails[i + 1][j].f = fNew;
	cellDetails[i + 1][j].g = gNew;
	cellDetails[i + 1][j].h = hNew;
	cellDetails[i + 1][j].parent_i = i;
	cellDetails[i + 1][j].parent_j = j;
}
			}
		}

		//----------- 3rd Successor (East) ------------

		 // Only process this cell if this is a valid one
		if (isValid(i, j + 1) == true)
		{
			// If the destination cell is the same as the current successor
			if (isDestination(i, j + 1, dest) == true)
			{
				// Set the Parent of the destination cell
				cellDetails[i][j + 1].parent_i = i;
				cellDetails[i][j + 1].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			// If the successor is already on the closed list or if it is blocked,
			// then ignore it. Else do the following
			else if (closedList[i][j + 1] == false
				&& isUnBlocked(grid, i, j + 1) == true)
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i, j + 1, dest);
				fNew = gNew + hNew;

				// If it isnt on the open list, add it to the open list. Make
				// the current square the parent of this square. Record the 
				// f, g, and h costs of the square cell
				//						OR
				// If it is on the open list already, check to see if this
				// path tp that square is better, using 'f' cost as the measure.
				if (cellDetails[i][j + 1].f == FLT_MAX
					|| cellDetails[i][j + 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i, j + 1)));

					// Update the details of this cell
					cellDetails[i][j + 1].f = fNew;
					cellDetails[i][j + 1].g = gNew;
					cellDetails[i][j + 1].h = hNew;
					cellDetails[i][j + 1].parent_i = i;
					cellDetails[i][j + 1].parent_j = j;
				}
			}
		}

		//----------- 4th Successor (West) ------------

		// Only process this cell if this is a valid one
		if (isValid(i, j - 1) == true) {
			// If the destination cell is the same as the
			// current successor
			if (isDestination(i, j - 1, dest) == true) {
				// Set the Parent of the destination cell
				cellDetails[i][j - 1].parent_i = i;
				cellDetails[i][j - 1].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			// If the successor is already on the closed list or if it is 
			// blocked, then ignore it. Else do the following
			else if (closedList[i][j - 1] == false
				&& isUnBlocked(grid, i, j - 1) == true)
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i, j - 1, dest);
				fNew = gNew + hNew;

				// If it isnt on the open list, add it to the open list. Make the
				// current square the parent of this square. Record the f, g,
				// and h costs of the square cell
				//						OR
				// If it is on the open list already, check to see if this path
				// to that square is better, using 'f' cost as the measure
				if (cellDetails[i][j - 1].f == FLT_MAX
					|| cellDetails[i][j - 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i, j - 1)));

					// Update the details of this cell
					cellDetails[i][j - 1].f = fNew;
					cellDetails[i][j - 1].g = gNew;
					cellDetails[i][j - 1].h = hNew;
					cellDetails[i][j - 1].parent_i = i;
					cellDetails[i][j - 1].parent_j = j;

				}
			}
		}

		//----------- 5th Successor (North-East) ------------

		// Only process this cell if this is a valid one
		if (isValid(i - 1, j + 1) == true) 
		{
			// If the destination cell is the same as the current successor
			if (isDestination(i - 1, j + 1, dest) == true) 
			{
				// Set the Parent of the destination cell
				cellDetails[i - 1][j + 1].parent_i = i;
				cellDetails[i - 1][j + 1].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			// If the successor is already on the closed list or if it is blocked
			// then ignore it. Else do the following
			else if (closedList[i - 1][j + 1] == false
				&& isUnBlocked(grid, i - 1, j + 1) == true) 
			{
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i - 1, j + 1, dest);
				fNew = gNew + hNew;

				// If it isnt on the open list, add it to the open list. Make the
				// current square the parent of this square. Record the f, g,
				// and h costs of the square cell
				//						OR
				// If it is on the open list already, check to see if this path
				// to that square is better, using 'f' cost as the measure
				if (cellDetails[i - 1][j + 1].f == FLT_MAX
					|| cellDetails[i - 1][j + 1].f > fNew) 
				{
					openList.insert(make_pair(fNew, make_pair(i - 1, j + 1)));

					// Update the details of this cell
					cellDetails[i - 1][j + 1].f = fNew;
					cellDetails[i - 1][j + 1].g = gNew;
					cellDetails[i - 1][j + 1].h = hNew;
					cellDetails[i - 1][j + 1].parent_i = i;
					cellDetails[i - 1][j + 1].parent_j = j;
				}
			}
		}

		//----------- 6th Successor (North-West) ------------

		// Only process this cell if this is a valid one
		if (isValid(i - 1, j - 1) == true) {
			// If the destination cell is the same as the current successor
			if (isDestination(i - 1, j - 1, dest) == true) {
				// Set the Parent of the destination cell
				cellDetails[i - 1][j - 1].parent_i = i;
				cellDetails[i - 1][j - 1].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			// If the successor is already on the closed list or if it is blocked
			// then ignore it. Else do the following
			else if (closedList[i - 1][j - 1] == false
				&& isUnBlocked(grid, i - 1, j - 1) == true)
			{
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i - 1, j - 1, dest);
				fNew = gNew + hNew;

				// If it isnt on the open list, add it to the open list. Make the
				// current square the parent of this square. Record the f, g,
				// and h costs of the square cell
				//						OR
				// If it is on the open list already, check to see if this path
				// to that square is better, using 'f' cost as the measure
				if (cellDetails[i - 1][j - 1].f == FLT_MAX
					|| cellDetails[i - 1][j - 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i - 1, j - 1)));

					// Update the details of this cell
					cellDetails[i - 1][j - 1].f = fNew;
					cellDetails[i - 1][j - 1].g = gNew;
					cellDetails[i - 1][j - 1].h = hNew;
					cellDetails[i - 1][j - 1].parent_i = i;
					cellDetails[i - 1][j - 1].parent_j = j;
				}
			}
		}

		//----------- 7th Successor (South-East) ------------

		// Only process this cell if this is a valid one
		if (isValid(i + 1, j + 1) == true) {
			// If the destination cell is the same as the current successor
			if (isDestination(i + 1, j + 1, dest) == true) {
				// Set the Parent of the destination cell
				cellDetails[i + 1][j + 1].parent_i = i;
				cellDetails[i + 1][j + 1].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			// If the successor is already on the closed list or if it is blocked
			// then ignore it. Else do the following
			else if (closedList[i + 1][j + 1] == false
				&& isUnBlocked(grid, i + 1, j + 1) == true)
			{
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i + 1, j + 1, dest);
				fNew = gNew + hNew;

				// If it isnt on the open list, add it to the open list. Make the
				// current square the parent of this square. Record the f, g,
				// and h costs of the square cell
				//						OR
				// If it is on the open list already, check to see if this path
				// to that square is better, using 'f' cost as the measure
				if (cellDetails[i + 1][j + 1].f == FLT_MAX
					|| cellDetails[i + 1][j + 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i + 1, j + 1)));

					// Update the details of this cell
					cellDetails[i + 1][j + 1].f = fNew;
					cellDetails[i + 1][j + 1].g = gNew;
					cellDetails[i + 1][j + 1].h = hNew;
					cellDetails[i + 1][j + 1].parent_i = i;
					cellDetails[i + 1][j + 1].parent_j = j;
				}
			}
		}

		//----------- 8th Successor (South-West) ------------

		// Only process this cell if this is a valid one
		if (isValid(i + 1, j - 1) == true) {
			// If the destination cell is the same as the current successor
			if (isDestination(i + 1, j - 1, dest) == true) {
				// Set the Parent of the destination cell
				cellDetails[i + 1][j - 1].parent_i = i;
				cellDetails[i + 1][j - 1].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}

			// If the successor is already on the closed list or if it is blocked
			// then ignore it. Else do the following
			else if (closedList[i + 1][j - 1] == false
				&& isUnBlocked(grid, i + 1, j - 1) == true)
			{
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i + 1, j - 1, dest);
				fNew = gNew + hNew;

				// If it isnt on the open list, add it to the open list. Make the
				// current square the parent of this square. Record the f, g,
				// and h costs of the square cell
				//						OR
				// If it is on the open list already, check to see if this path
				// to that square is better, using 'f' cost as the measure
				if (cellDetails[i + 1][j - 1].f == FLT_MAX
					|| cellDetails[i + 1][j - 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i + 1, j - 1)));

					// Update the details of this cell
					cellDetails[i + 1][j - 1].f = fNew;
					cellDetails[i + 1][j - 1].g = gNew;
					cellDetails[i + 1][j - 1].h = hNew;
					cellDetails[i + 1][j - 1].parent_i = i;
					cellDetails[i + 1][j - 1].parent_j = j;
				}
			}
		}
	}

	// When the destination cell is not found and the open list is empty,
	// then we conclude that we failed to reach the destination cell.
	// This may happen when there is no way to destination cell (due to blockages)
	if (foundDest == false)
		cout << "Failed to find the Destination Cell" << endl;

	return;
}

// Driver program to test above function
int main()
{
	// Description of the grid:
	// 1 --> The cell is not blocked
	// 0 --> The cell is blocked
	
	int grid[ROW][COL]
		= { { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
			{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
			{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
			{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
			{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
			{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
			{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
			{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
			{ 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } };

	// Source is the left-most bottom-most corner
	Pair src = make_pair(8, 0);

	// Destination is the left-most top-most corner
	Pair dest = make_pair(0, 0);

	aStarSearch(grid, src, dest);

	return 0;
}

*/