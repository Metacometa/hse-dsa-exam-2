#include "DisjointSet.h"

void DisjointSet::MakeSet(const vector<int>& nodes)
{
	f.resize(nodes.size() + 1);

	for (int i = 0; i < f.size(); ++i) {
		f[i] = i;
	}
}

void DisjointSet::Union(const int& x, const int& y)
{
	for (auto& i : f) {
		if (i == y) {
			i = x;
		}
	}
}

int DisjointSet::Find(const int& x)
{
	if (x < f.size()) {
		return f[x];
	}
	else {
		return -1;
	}
}
