#pragma once
#pragma once

#include <iostream>
#include "graphs.h"

#include <vector>

class Ticket10
{
	int DEAD_NODE = -1;
	vector<bool> used;
	vector<int> tin;
	vector<int> tup;

	set<int> articulationPoints;
	int timer = 0;

public:
	void findArticulationPoints(const vector<pair<int, int>>& graph) {
		used.resize(graph.size() + 1);
		tin.resize(graph.size() + 1);
		tup.resize(graph.size() + 1);

		dfs(1, DEAD_NODE, graph);

		std::cout << "Ticket 10: Find articulation points:" << std::endl;
		for (auto& point : articulationPoints) {
			cout << point << ", " << endl;
		}
		cout << endl;

	}

	void dfs(const int& vertice, const int& parent, const vector<pair<int, int>>& graph) {
		used[vertice] = true;
		tup[vertice] = tin[vertice] = timer++;

		int children = 0;
		for (auto& to : getNeighbours(graph, vertice)) {
			if (to == parent) {
				continue;
			}

			if (used[to]) {
				tup[vertice] = min(tup[vertice], tin[to]);
			}
			else {
				children++;
				dfs(to, vertice, graph);
				tup[vertice] = min(tup[vertice], tup[to]);

				if (tin[vertice] <= tup[to] and parent != DEAD_NODE) {
					articulationPoints.emplace(vertice);
				}
			}
		}

		if (parent == DEAD_NODE and children > 1) {
			articulationPoints.emplace(vertice);
		}
	}

	vector<int> getNeighbours(const vector<pair<int, int>>& graph, const int& node) {
		vector<int> neighbours;

		for (auto& i : graph) {
			if (i.first == node) {
				neighbours.push_back(i.second);
			}
			else if (i.second == node) {
				neighbours.push_back(i.first);
			}
		}

		return neighbours;
	}
};


