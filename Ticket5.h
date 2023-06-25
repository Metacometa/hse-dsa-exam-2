#pragma once
#include "graphs.h"
#include <queue>

class Ticket5
{
	vector<bool> used;
public:
	void bfs(const vector<vector<bool>> &graph, const int&node) {
		queue<int> q;
		q.push(node);
		used[node] = true;

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			cout << current << " -> ";

			for (int i = 0; i < graph[current].size(); ++i) {
				if (graph[current][i] == true and used[i] == false) {
					q.push(i);
					used[i] = true;
				}
			}
		}
	}

	void dfs(const vector<vector<bool>>& graph, const int& node) {
		cout << node << " -> ";
		used[node] = true;

		for (int i = 0; i < graph[node].size(); ++i) {
			if (graph[node][i] == true and used[i] == false) {
				dfs(graph, i);
			}
		}

	}
	
	void bfsAndDfs(const vector<vector<bool>>& graph, const int& node) {
		std::cout << "Ticket 5: Bfs, Dfs:" << endl;

		cout << "Bfs: ";

		used.resize(graph.front().size());
		bfs(graph, node);

		cout << endl;

		cout << "Dfs: ";

		used.clear();

		used.resize(graph.front().size());
		dfs(graph, node);
		cout << endl;
		cout << endl;
	}
};

