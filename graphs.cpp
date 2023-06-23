#include "graphs.h"

vector<int> getNodes(const vector<WeightedNode> &graph)
{
	set<int> nodes;
	for (auto& i : graph) {
		nodes.insert(i.from);
		nodes.insert(i.to);
	}

	return vector<int>(nodes.begin(), nodes.end());
}

vector<int> getNodes(const vector<pair<int, int>> &graph)
{
	set<int> nodes;
	for (auto& i : graph) {
		nodes.insert(i.first);
		nodes.insert(i.second);
	}

	return vector<int>(nodes.begin(), nodes.end());
}

//ticket 6
vector<pair<int, int>> ticket6_test1{
	{1, 2},
	{1, 3},
	{2, 3},
	{2, 4},
	{3, 4},
	{5, 6},
	{6, 7},
	{7, 5},
	{8, 9},
	{10, 10},
	{11, 11}
};

vector<pair<int, int>> ticket6_test2{
	{1, 2},
	{1, 3},
	{2, 4},
	{2, 5},
	{6,7},
	{8,9}
};

//ticket 7
vector<pair<int, int>> ticket7_test1 { 
	{ 1, 2 }, 
	{ 1, 3 }, 
	{ 2, 4 }, 
	{ 2, 5 }, 
	{ 3, 4 }, 
	{ 3, 6 }, 
	{ 4, 5 }, 
	{ 4, 6 } 
};
vector<pair<int, int>> ticket7_test2{
	{3,8}, {3,10},
	{7,8}, {7,11},
	{5,11},
	{11,2}, {11,9}, {11,10},
	{8,9}
};
vector<pair<int, int>> ticket7_test3{
	{5,2}, {5,0},
	{4,0}, {4,1},
	{2,3},
	{3,1}
};

//ticket 8

vector<pair<int, int>> ticket8_test1{
	{ 0, 7 },
	{ 1, 9 },
	{ 2, 9 },
	{ 2, 10},
	{ 3, 8 },
	{ 4, 2 },
	{ 5, 3 },
	{ 5, 10},
	{ 6, 0},
	{ 6, 1},
	{ 6, 4},
	{ 7 ,6},
	{ 7, 1},
	{ 8, 5 },
	{ 9, 4},
	{ 10, 8},
	{ 11, 2},
	{ 11, 9}
};

//ticket 9
vector<pair<int, int>> ticket9_test1{
	{1, 2},
	{2, 3},
	{2, 4},
	{3, 4}
};

vector<pair<int, int>> ticket9_test2{
	{1, 2},
	{1, 3},
	{2, 3},
	{2, 6},
	{4, 5},
	{4, 6},
	{5, 6},
	{6, 7},
	{7, 8},
	{7, 11},
	{8, 9},
	{9, 10},
	{10, 11}
};
vector<pair<int, int>> ticket9_test3{
	{1,2},
	{1, 5},
	{2, 3},
	{3, 4},
	{4, 1}
};

//Dijkstra tests
vector<WeightedNode> dijkstra_test1{
	{10, 1, 2},
	{100, 1, 5},
	{30, 1, 4},
	{50, 2, 3},
	{10, 3, 5},
	{20, 4, 3},
	{60, 4, 5}
};

vector<WeightedNode> dijkstra_test2 {
	{2, 1, 2},
	{6, 1, 3},
	{5, 2, 4},
	{8, 3, 4},
	{15, 4, 6},
	{10, 4, 5},
	{6, 6, 7},
	{2, 5, 7},
	{6, 5, 6}
};



//ticket 8
vector<WeightedNode> mst_test1{
	{50, 1, 2},
	{100, 2, 3}
};

vector <WeightedNode> mst_test2{
	{4,	2, 5},
	{6,	8, 6},
	{7,	2, 3},
	{7,	7, 8},
	{8,	0, 7},
	{1,	7, 6},
	{2,	8, 2},
	{2,	6, 5},
	{4,	0, 1},
	{8,	1, 2},
	{9,	3, 4},
	{10, 5,	4},
	{11, 1,	7},
	{14, 3,	5},
};

vector<WeightedNode> mst_test3{
	{10, 1, 6},
	{28, 1, 2},
	{25, 6, 5},
	{16, 2, 3},
	{14, 2, 7},
	{24, 7, 5},
	{18, 7, 4},
	{22, 5, 4},
	{12, 3, 4}
};

vector<WeightedNode> mst_test4{
	{4, 0, 1},
	{8, 0, 7},
	{11, 1, 7},
	{8, 1, 2},
	{1, 7, 6},
	{7, 7, 8},
	{6, 6, 8},
	{2, 2, 8},
	{4, 2, 5},
	{7, 2, 3},
	{2, 6, 5},
	{14, 3, 5},
	{9, 3, 4},
	{10, 4, 5}
};


