#pragma once

#include <iostream>
#include "graphs.h"

#include <vector>

class Ticket9
{
	vector<bool> used;
	vector<int> tin;
	vector<int> tup;

	vector<pair<int, int>> bridges;
	int timer = 0;

public:
	void findBridges(const vector<pair<int, int>> &graph) {
		used.resize(graph.size() + 1);
		tin.resize(graph.size() + 1);
		tup.resize(graph.size() + 1);

		dfs(graph.front().first, -1, graph);

		std::cout << "Ticket 9: Find bridges:" << std::endl;
		for (auto& bridge : bridges) {
			cout << bridge.first << "---" << bridge.second << endl;
		}
		cout << endl;

	}

	void dfs(const int& vertice, const int& parent, const vector<pair<int, int>>& graph) {
		used[vertice] = true;
		tup[vertice] = tin[vertice] = timer++;

		for (auto& to : getNeighbours(graph, vertice)) {
			if (to == parent) {
				continue;
			}

			if (used[to]) {
				tup[vertice] = min(tup[vertice], tin[to]);
			}
			else {
				dfs(to, vertice, graph);
				tup[vertice] = min(tup[vertice], tup[to]);

				if (tin[vertice] < tup[to]) {
					if (vertice < to) {
						bridges.emplace_back(vertice, to);
					}
					else {
						bridges.emplace_back(to, vertice);
					}
				}
			}
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

