#include <iostream>
#include "graphs.h"
#include <vector>

class Ticket4 {
	vector<vector<int>> prefix;
public:
	void PrefixSumMatrix(const vector<vector<int>>& matrix, const int& x1, const int& y1, const int& x2, const int &y2) {
		int mappedX1 = x1 + 1;
		int mappedY1 = y1 + 1;
		int mappedX2 = x2 + 1;
		int mappedY2 = y2 + 1;

		prefix.resize(matrix.size() + 1);
		for (auto& i : prefix) {
			i.resize(matrix.front().size() + 1);
		}

		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix.front().size(); ++j) {
				//bijection to prefix
				prefix[i + 1][j + 1] = matrix[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
			}
		}

		for (int i = 0; i < prefix.size(); ++i) {
			cout << i << " :";
			for (int j = 0; j < prefix.front().size(); ++j) {
				//bijection to prefix
				cout << prefix[i][j] << " ";
			}
			cout << endl;
		}
		
		int answer = prefix[mappedY2][mappedX2] - prefix[mappedY2 ][mappedX1 - 1] - prefix[mappedY1 - 1][mappedX2] + prefix[mappedY1 - 1][mappedX1 - 1];
		std::cout << "Ticket 4: 2d Prefix sum matrix:" << std::endl;
		std::cout << "Querie: From(" << x1 << ", " << y1 << ") To(" << x2 << ", " << y2 << ") is " << answer << endl;
		cout << endl;
	}
};