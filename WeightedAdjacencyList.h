#pragma once
#include <set>
#include <vector>

using namespace std;

struct WeightedAdjacencyList
{
	int weight = -1;
	int from = -1;
	int to = -1;
	WeightedAdjacencyList(const int& weight_, const int& from, const int& to);
	WeightedAdjacencyList(const WeightedAdjacencyList& source);
	WeightedAdjacencyList();
};

