#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "DisjointSet.h"

#include "WeightedAdjacencyList.h"

using namespace std;

vector<int> getNodes(const vector<WeightedAdjacencyList> &graph);
vector<int> getNodes(const vector<pair<int, int>> &graph);

//ticket 6 tests
extern vector<pair<int, int>> ticket6_test1;
extern vector<pair<int, int>> ticket6_test2;


//ticket 7 tests
extern vector<pair<int, int>> ticket7_test1;
extern vector<pair<int, int>> ticket7_test2;
extern vector<pair<int, int>> ticket7_test3;

//ticket 16/17 tests
extern vector<WeightedAdjacencyList> ticket16_test1;
extern vector<WeightedAdjacencyList> ticket16_test2;
extern vector<WeightedAdjacencyList> ticket16_test3;
extern vector<WeightedAdjacencyList> ticket16_test4;

