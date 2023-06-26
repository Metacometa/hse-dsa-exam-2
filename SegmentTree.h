#pragma once
//#include "graphs.h"

#include <memory>
#include <vector>
using namespace std;

struct Node {
	int value = 0;
	shared_ptr<Node> left = {};
	shared_ptr<Node> right = {};
	Node() {};
	~Node() {};
	Node(vector<int>& arr, const int& l, const int& r) {
		if (r - l == 0) {
			value = arr[l];
			cout << l << ", " << r << " " << value << endl;
			return;
		}

		if (r - l > 0) {
			int mid = (r + l) / 2;
			left = shared_ptr<Node>(new Node(arr, l, mid));
			right = shared_ptr<Node>(new Node(arr, mid + 1, r));
			value += left.get()->value;
			value += right.get()->value;
			cout << l << ", " << r << " " << value << endl;
		}

	}
};

class SegmentTree
{
	shared_ptr<Node> root = {};
public:	
	SegmentTree(vector<int>& arr) {
		root = shared_ptr<Node>(new Node(arr, 0, arr.size() - 1));

	}
};	

