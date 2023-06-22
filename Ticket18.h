#pragma once
#include "graphs.h"
#include "math.h"
#include <algorithm>

using namespace std;

class Ticket18
{
	int INF = 10000;
	DisjointSet ds;
public:
	vector<int> getVerticesByComponent(const int& component, const int &n) {
		vector<int>vertices;
		for (int i = 0; i < n; ++i) {
			if (ds.Find(i) == component) {
				vertices.push_back(i);
			}
		}

		return vertices;
	}

	void Boruvka(const vector<WeightedAdjacencyList>& graph) {
		vector<int> nodes = getNodes(graph);
		set<int> components;
		ds.MakeSet(nodes);

		vector<WeightedAdjacencyList> minimumSpanningTree;
		while (minimumSpanningTree.size() != nodes.size() - 1) {
			components.clear();
			for (auto& i : nodes) {
				components.insert(ds.Find(i));
			}

			for (auto& component : components) {
				vector<int>vertices = getVerticesByComponent(component, nodes.size());
				WeightedAdjacencyList minimumEdge(INF, 0, 0);
				for (auto& vertice : vertices) {
					for (auto& node : graph) {
						if (node.from == vertice or node.to == vertice) {
							if (find(minimumSpanningTree.begin(), minimumSpanningTree.end(), node) == minimumSpanningTree.end()) {
								minimumEdge = min(minimumEdge, node, [](const WeightedAdjacencyList& a, const WeightedAdjacencyList& b) { return a.weight < b.weight; });
							}

						}
					}
				}

				if (minimumEdge.weight != INF) {
					minimumSpanningTree.emplace_back(minimumEdge);
					ds.Union(ds.Find(minimumEdge.from), ds.Find(minimumEdge.to));
				}

			}

			sort(minimumSpanningTree.begin(), minimumSpanningTree.end(), [](const WeightedAdjacencyList& a, const WeightedAdjacencyList& b) {
				if (a.weight != b.weight) {
					return a.weight < b.weight;
				}
				else if (a.from != b.from) {
					return a.from < b.from;
				}
				else {
					a.to < b.to;
				}
				return false;
				});
			auto kek = unique(minimumSpanningTree.begin(), minimumSpanningTree.end());
			minimumSpanningTree.resize(std::distance(minimumSpanningTree.begin(), kek));
		}

		std::cout << "Ticket 18: Minimum spanning tree - Boruvka:" << std::endl;
		for (auto& i : minimumSpanningTree) {
			cout << "(" << i.weight << ", " << i.from << ", " << i.to << ")" << endl;
		}
		std::cout << std::endl;
	}
};

