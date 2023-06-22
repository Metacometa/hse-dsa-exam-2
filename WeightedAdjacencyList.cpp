#include "WeightedAdjacencyList.h"

WeightedNode::WeightedNode(const int& weight_, const int& from_, const int& to_) : weight(weight_), from(from_), to(to_)
{
}


WeightedNode::WeightedNode(const WeightedNode& source)
{
	this->weight = source.weight;
	this->from = source.from;
	this->to = source.to;
}

WeightedNode::WeightedNode()
{
}

bool operator==(const WeightedNode& a, const WeightedNode& b)
{
	return a.weight == b.weight and a.from == b.from and a.to == b.to;
}
