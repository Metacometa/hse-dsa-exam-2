#pragma once
#include <vector>
#include "graphs.h"

class Ticket16
{
	DisjointSet ds;

public:
	void Kruskal(vector<WeightedNode> &graph) {
		vector<WeightedNode> minimumSpanningTree;

		ds.MakeSet(getNodes(graph));

		sort(graph.begin(), graph.end(), [](const WeightedNode& a, const WeightedNode& b) { return a.weight < b.weight; });

		for (auto& i : graph) {
			if (ds.Find(i.from) != ds.Find(i.to)) {
				minimumSpanningTree.emplace_back(i);
				ds.Union(ds.Find(i.from), ds.Find(i.to));
			}
		}

		std::cout << "Ticket 16: Minimum spanning tree - Kraskal:" << std::endl;
		for (auto& i : minimumSpanningTree) {
			cout << "(" << i.weight << ", " << i.from << ", " << i.to << ")" << endl;
		}
		std::cout << std::endl;

	}

};

