#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "DisjointSet.h"

#include "WeightedNode.h"

using namespace std;

vector<int> getNodes(const vector<WeightedNode> &graph);
vector<int> getNodes(const vector<pair<int, int>> &graph);

//ticket 4
extern vector<vector<int>> ticket4_test1;
extern vector<vector<int>> ticket4_test2;

//ticket 6 tests
extern vector<pair<int, int>> ticket6_test1;
extern vector<pair<int, int>> ticket6_test2;


//ticket 7 tests
extern vector<pair<int, int>> ticket7_test1;
extern vector<pair<int, int>> ticket7_test2;
extern vector<pair<int, int>> ticket7_test3;

//ticket 8 tests
extern vector<pair<int, int>> ticket8_test1;

//ticket 9 tests
extern vector<pair<int, int>> ticket9_test1;
extern vector<pair<int, int>> ticket9_test2;
extern vector<pair<int, int>> ticket9_test3;

//ticket 11 tests
extern vector<vector<int>> ticket11_test1;

//ticket 12 Dijkstra
extern vector<WeightedNode> dijkstra_test1;
extern vector<WeightedNode> dijkstra_test2;

extern vector<WeightedNode> bellman_ford_test1;

//ticket 16/17/18/19 tests
extern vector<WeightedNode> mst_test1;
extern vector<WeightedNode> mst_test2;
extern vector<WeightedNode> mst_test3;
extern vector<WeightedNode> mst_test4;

