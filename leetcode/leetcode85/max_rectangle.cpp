#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int> > ones(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (i == 0) { ones[i][j] = matrix[i][j]-'0'; continue; }
                if (matrix[i][j] == '0') ones[i][j] = 0;
                else ones[i][j] = ones[i-1][j]+matrix[i][j]-'0';
            }
        }

        int max_area = 0;
        for (int i = 0; i < ones.size(); ++i) {
            stack<int> st; int area = 0;
            ones[i].push_back(0);
            for (int j = 0; j < ones[i].size(); ++j) {
                while (!st.empty() && ones[i][st.top()]>ones[i][j]) {
                    int idx = st.top(); st.pop();
                    area = max(area, ones[i][idx]*(j-(st.empty()?0:st.top()+1)));
                }
                st.push(j);
            }
            max_area = max(max_area, area);
        }
        return max_area;
    }
};

int main()
{
	char a[3][5] = {
        {'0', '0', '0', '1', '1'},
        {'0', '1', '0', '1', '1'},
        {'0', '1', '0', '1', '0'}
	};
	vector<vector<char> > v(sizeof(a)/sizeof(a[0]), vector<char>(sizeof(a[0])/sizeof(a[0][0]), 0));
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        for (int j = 0; j < sizeof(a[0])/sizeof(a[0][0]); ++j) {
            v[i][j] = a[i][j];
        }
    }
	Solution sol;
	cout << sol.maximalRectangle(v) << endl;
	return 0;
}
