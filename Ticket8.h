#pragma once
#include <iostream>
#include "Ticket7.h"
#include "graphs.h"
#include <vector>
#include <utility>

using namespace std;

class Ticket8
{
	Ticket7 ticket7;
	vector<int> components;

public:
	void findStronglyConnectedComponents(const vector<pair<int, int>>& graph) {
		vector<pair<int, int>> invertedGraph = getInvertedGraph(graph);
		vector<int> topologicalOrder = ticket7.getTopologicalSort(invertedGraph);
		components.resize(getNodes(graph).size());

		int component = 1;
		for (auto& node : topologicalOrder) {
			if (components[node] == 0) {
				dfs(node, graph, component);
				component++;
			}

		}

		std::cout << "Ticket 8: Strong connection components:" << std::endl;
		for (int i = 1; i < component; ++i) {
			cout << "Component #" << i << ":" << endl;
			for (int j = 0; j < components.size(); ++j) {
				if (components[j] == i) {
					cout << j << " " << i << endl;
				}
			}
		}

		cout << endl;
	}

	void dfs(const int &node, const vector<pair<int, int>>& graph, const int& component) {
		components[node] = component;
		for (auto& i : graph) {
			if (i.first == node and components[i.second] == 0) {
				dfs(i.second, graph, component);
			}
		}
	}

	vector<pair<int, int>> getNeighbours(const vector<pair<int, int>>& graph) {

	}

	vector<pair<int, int>> getInvertedGraph(const vector<pair<int, int>>& graph) {
		vector<pair<int, int>> invertedGraph;
		for (auto& node : graph) {
			invertedGraph.emplace_back(node.second, node.first);
		}

		return invertedGraph;
	}
};

