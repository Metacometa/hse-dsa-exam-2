#include "graphs.h"



vector<pair<int, int>> test_graph_1 { 
	{ 1, 2 }, 
	{ 1, 3 }, 
	{ 2, 4 }, 
	{ 2, 5 }, 
	{ 3, 4 }, 
	{ 3, 6 }, 
	{ 4, 5 }, 
	{ 4, 6 } 
};

vector<pair<int, int>> test_graph_2{
	{3,8}, {3,10},
	{7,8}, {7,11},
	{5,11},
	{11,2}, {11,9}, {11,10},
	{8,9}
};
vector<pair<int, int>> test_graph_3{
	{5,2}, {5,0},
	{4,0}, {4,1},
	{2,3},
	{3,1}
};