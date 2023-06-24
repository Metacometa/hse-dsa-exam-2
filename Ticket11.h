#pragma once
#include "graphs.h"
#include <stack>

class Ticket11
{
	stack<int> st;
	vector<int> c;

public:
	void findEulerianCircuit(vector<vector<int>> graph) {
		std::cout << "Ticket 11: Eulerian circuit:" << std::endl;
		if (!isEulerian(graph)) {
			cout << "Graph has no eulerian circuit" << endl;
			cout << endl;
			return;
		}

		dfs(graph, 0);
		reverse(c.begin(), c.end());
		for (auto& i : c) {
			cout << i << " --> ";
		}
		cout << "end" << endl;
		cout << endl;

	}

	void dfs(vector<vector<int>>& graph, const int&node) {
		int current = node;
		st.push(node);

		while (!st.empty()) {
			int neighbour = getNeighbour(graph, current);

			if (graph[current][neighbour] != 0) {
				graph[current][neighbour] = 0;
				graph[neighbour][current] = 0;
				st.push(neighbour);

				current = neighbour;
			}
			else {
				c.push_back(current);
				st.pop();
				if (!st.empty()) {
					current = st.top();
				}

			}
		}

	}

	int getNeighbour(const vector<vector<int>>& graph, const int& node) {
		for (int i = 0; i < graph[node].size(); ++i) {
			if (graph[node][i] != 0) {
				return i;
				break;
			}
		}

		return 0;
	}

	bool isEulerian(const vector<vector<int>> graph) {
		for (auto& line : graph) {
			int neighbourCounter = 0;
			for (auto& tie : line) {
				if (tie != 0) {
					neighbourCounter++;
				}
			}

			if (neighbourCounter % 2 != 0) {
				return false;
			}
		}

		return true;
	}
};

