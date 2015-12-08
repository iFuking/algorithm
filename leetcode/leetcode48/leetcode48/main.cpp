#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void swap(int &n1, int &n2, int &n3, int &n4)
	{
		int n = n4; n4 = n3; n3 = n2; n2 = n1; n1 = n;
		return;
	}

    void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size()-1;
		for (int i = 0; i < matrix.size()/2; ++i) {
			for (int j = i; j < matrix[i].size()-1-i; ++j) {
				swap(matrix[i][j], matrix[j][n-i], 
					matrix[n-i][n-j], matrix[n-j][i]);	
			}
		}
		return;
    }
};

int main()
{
	Solution sol;
	/*int a[][3] = {
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9}
	};*/
	int a[][4] = {
		{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}
	};
	vector<vector<int>> v(sizeof(a)/sizeof(a[0]), vector<int>(sizeof(a[0])/sizeof(a[0][0])));
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
		for (int j = 0; j < sizeof(a[i])/sizeof(a[i][0]); ++j) {
			v[i][j] = a[i][j];
		}
	}
	sol.rotate(v);
	return 0;
}