#pragma once
#include "graphs.h"

class Ticket14
{
	int INF = 10000;
	vector<vector<int>> distances;
public:
	void Floyd(const vector<WeightedNode>& graph) {
		int n = getNodes(graph).size();

		initDistances(graph, n);

		calculateDistances(graph, n);
	
		std::cout << "Ticket 14: Finding the shorted path - Floyd:" << std::endl;
		printDistances();
		cout << endl;
	}

	void calculateDistances(const vector<WeightedNode>& graph, const int &n) {
		for (int iteration = 0; iteration < n; ++iteration) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (distances[i][j] != 0) {
						distances[i][j] = min(distances[i][j],
							distances[i][iteration] + distances[iteration][j]);
					}
				}
			}
		}
	}

	void printDistances() {
		for (auto& line : distances) {
			for (auto& distance : line) {
				cout << distance << " ";
			}
			cout << endl;
		}
	}

	void initDistances(const vector<WeightedNode>& graph, const int &n) {
		distances.resize(n);
		for (int line = 0; line < n; ++line) {
			distances[line].resize(n, INF);
			distances[line][line] = 0;
		}

		for (auto& node : graph) {
			distances[node.from][node.to] = min(distances[node.from][node.to], node.weight);
			if (distances[node.from][node.to] == 0) {
				distances[node.from][node.to] = node.weight;
			}
		}
	}

};

