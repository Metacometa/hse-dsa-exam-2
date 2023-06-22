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
	WeightedNode getClosest(vector<WeightedNode>& graph) {
		WeightedNode temp(INF, 0, 0);
		for (int i = 0; i < used.size(); ++i) {
			if (used[i]) {
				for (auto& node : graph) {
					if ((node.to == i and node.from != i and used[node.from] == false)
						or (node.to != i and node.from == i and used[node.to] == false)) {
						temp = min(temp, node, [](const WeightedNode &a, const WeightedNode &b) { return a.weight < b.weight;});
					}
				}
			}
		}
		return temp;
	}

	void Prim(vector<WeightedNode>& graph) {
		vector<WeightedNode> minimumSpanningTree;

		used.resize(getNodes(graph).size() + 1);

		used[graph.front().from] = true;
		WeightedNode temp;
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

