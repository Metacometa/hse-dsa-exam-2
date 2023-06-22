#pragma once
#include <set>
#include <vector>

using namespace std;

struct WeightedNode
{
	int weight = -1;
	int from = -1;
	int to = -1;
	WeightedNode(const int& weight_, const int& from, const int& to);
	WeightedNode(const WeightedNode& source);
	WeightedNode();

	friend bool operator==(const WeightedNode& a, const WeightedNode& b);
};

