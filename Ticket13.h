#pragma once
#include "graphs.h"

class Ticket13
{
	int INF = 10000;
	vector<int> distance;
	vector<int> parents;
public:
	void BellmanFord(const vector<WeightedNode> &graph, const int&from, const int&to) {
		int n = getNodes(graph).size() + 1;
		distance.resize(n, INF);
		parents.resize(n, 0);
		distance[from] = 0;

		for (int i = 0; i < n - 1; ++i) {
			for (auto& node : graph) {
				if (distance[node.from] + node.weight < distance[node.to]) {
					distance[node.to] = distance[node.from] + node.weight;
					parents[node.to] = node.from;
				}
			}
		}

		vector<int> path;
		int buildPath = to;
		while (buildPath != 0) {
			path.push_back(buildPath);
			buildPath = parents[buildPath];
		}
		reverse(path.begin(), path.end());

		std::cout << "Ticket 13: Finding the shorted path - Bellman-Ford:" << std::endl;
		cout << "The weight of path is " << distance[to] << endl;
		cout << "Path: ";
		for (auto& i : path) {
			cout << i << " --> ";
		}
		cout << "end" << endl;
		cout << endl;
	}
};

