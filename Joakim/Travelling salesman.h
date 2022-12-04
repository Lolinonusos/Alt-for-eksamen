#pragma once

#include <iostream>

using namespace std;


int n = 4;

//Dynamic Programming array
int dp[16][4];

// Adj Matrix which defines the graph
int dist[10][10] =
{
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};

// If all cities have been visited
int visitedAll = (1 << n) - 1;


// tsp = travellingSalesmanProblem	||	mask = set of cities that have been visited	 ||	 pos = index to show where we are and where to go
int tsp(int mask, int pos)
{
	// If all cities have been visited
	if (mask == visitedAll)
	{
		return dist[pos][0];
	}

	// Lookup
	if (dp[mask][pos] != -1)
	{
		return dp[mask][pos];
	}

	int ans = INT_MAX;
	// Try to go to unvisited city
	for (int city = 0; city < n; city++)
	{
		if ((mask & (1 << city)) == 0)
		{
			int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
			ans = min(ans, newAns);
		}
	}

	return dp[mask][pos] = ans;
}
