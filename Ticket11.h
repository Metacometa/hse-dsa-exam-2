#pragma once
#include <iostream>
#include "graphs.h"
#include <vector>

using namespace std;

class Ticket11
{
	int INF = 10000;
	vector<bool> used;
	vector<int> parent;
	vector<int> distance;
public:
	void Dijkstra(const vector<WeightedNode> &graph, const int &from, const int &to) {
		int start = from;
		int end = to;

		vector<int> vertices = getNodes(graph);
		used.resize(vertices.size() + 1);
		parent.resize(vertices.size() + 1);
		distance.resize(vertices.size() + 1, INF);

		int visited_count = 0;
		distance[start] = 0;

		while (visited_count != vertices.size()) {
			vector<WeightedNode> neighbours = getNeighbours(start, graph);
			for (auto& neighbour : neighbours) {
				if (neighbour.weight + distance[start] < distance[neighbour.to]) {
					distance[neighbour.to] = neighbour.weight + distance[start];
					parent[neighbour.to] = start;
				}
			}

			int min_weight = INF;
			int min_i = 0;
			for (int i = 1; i < distance.size(); ++i) {
				if (used[i] == false and i != start) {
					if (distance[i] < min_weight and distance[i] != 0) {

						min_weight = distance[i];
						min_i = i;
					}
				}
			}

			used[start] = true;
			start = min_i;
			visited_count++;

		}

		vector<int> path;
		int buildPath = end;
		while (buildPath != 0) {
			path.push_back(buildPath);
			buildPath = parent[buildPath];

		}

		reverse(path.begin(), path.end());

		std::cout << "Ticket 11: Finding the shorted path - Dijkstra:" << std::endl;
		for (auto& i : path) {
			cout << i << " --> ";
		}
		cout << "end" << endl;
		cout << endl;

	}

	vector<WeightedNode> getNeighbours(const int &source, const vector<WeightedNode> &graph) {
		vector<WeightedNode> neighbours;

		for (auto& i : graph) {
			if (i.from == source and used[i.to] == false) {
				neighbours.emplace_back(i.weight, i.from, i.to);
			}
			else if (used[i.from] == false and i.to == source) {
				neighbours.emplace_back(i.weight, i.to, i.from);
			}
		}

		return neighbours;
	}
};

