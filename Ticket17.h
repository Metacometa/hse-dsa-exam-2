#pragma once
#include <vector>
#include "graphs.h"
#include <math.h>

using namespace std;

class Ticket17
{
	int INF = 100000;
	vector<bool> used;
public:
	WeightedAdjacencyList getClosest(vector<WeightedAdjacencyList>& graph) {
		WeightedAdjacencyList temp(INF, 0, 0);
		for (int i = 0; i < used.size(); ++i) {
			if (used[i]) {
				for (auto& node : graph) {
					if ((node.to == i and node.from != i and used[node.from] == false)
						or (node.to != i and node.from == i and used[node.to] == false)) {
						temp = min(temp, node, [](const WeightedAdjacencyList &a, const WeightedAdjacencyList &b) { return a.weight < b.weight;});
					}
				}
			}
		}
		return temp;
	}

	void Prim(vector<WeightedAdjacencyList>& graph) {
		vector<WeightedAdjacencyList> minimumSpanningTree;

		used.resize(getNodes(graph).size() + 1);

		used[graph.front().from] = true;
		WeightedAdjacencyList temp;
		for (int i = 0; i < used.size(); ++i) {
			temp = getClosest(graph);
			if (temp.weight != INF) {
				minimumSpanningTree.emplace_back(temp);
				used[temp.from] = true;
				used[temp.to] = true;
			}
		}

		std::cout << "Ticket 17: Minimum spanning tree - Prim:" << std::endl;
		for (auto& i : minimumSpanningTree) {
			cout << "(" << i.weight << ", " << i.from << ", " << i.to << ")" << endl;
		}
		std::cout << std::endl;
		
	}
};

