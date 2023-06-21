#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
	vector<int> f;
public:
	DisjointSet() = default;
	void MakeSet(const vector<int> &nodes);
	void Union(const int& x, const int& y);
	int Find(const int& x);
};