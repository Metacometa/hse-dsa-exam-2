#pragma once

#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include "graphs.h"

using namespace std;
class Ticket6
{
	DisjointSet ds;

public:
	void findConnectedComponents(const vector<pair<int, int>> &graph) {
		ds.MakeSet(getNodes(graph));

		for (auto& i : graph) {
			ds.Union(ds.Find(i.first), ds.Find(i.second));
		}

		std::cout << "Ticket 6: Connection components:" << std::endl;

		vector<pair<int, int>> connectedComponents;

		for (int i = 1; i < getNodes(graph).size() + 1; ++i) {
			connectedComponents.emplace_back(make_pair(i, ds.Find(i)));
		}

		sort(connectedComponents.begin(), connectedComponents.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
		for (auto& i : connectedComponents) {
			cout << i.first << ": " << i.second << endl;
		}
		cout << endl;
	}
};

