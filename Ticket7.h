#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Ticket7
{
	vector<bool> used;
	vector<int> order;

public:
	Ticket7() {
		used.resize(100);
	}
	void topological_sort(const vector<pair<int, int>>& graph) {
		for (auto& i : graph) {
			if (!used[i.first]) {
				dfs(i.first, graph);
			}
		}
		reverse(order.begin(), order.end());
		std::cout << "Ticket 7: Topological sort" << std::endl;
		for (auto& i : order) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	void dfs(const int &start, const vector<pair<int, int>>& graph) {
		used[start] = true;
		for (auto& output : getOutput(start, graph)) {
			if (!used[output]) {
				dfs(output, graph);
			}
		}
		order.push_back(start);
	}

	vector<int> getOutput(const int& source, const vector<pair<int, int>>& graph) {
		vector<int> output;
		for (auto& node : graph) {
			if (node.first == source and used[node.second] == false) {
				output.push_back(node.second);
			}
		}
		return output;
	}
};

