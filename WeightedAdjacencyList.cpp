#include "WeightedAdjacencyList.h"

WeightedAdjacencyList::WeightedAdjacencyList(const int& weight_, const int& from_, const int& to_) : weight(weight_), from(from_), to(to_)
{
}


WeightedAdjacencyList::WeightedAdjacencyList(const WeightedAdjacencyList& source)
{
	this->weight = source.weight;
	this->from = source.from;
	this->to = source.to;
}

WeightedAdjacencyList::WeightedAdjacencyList()
{
}
