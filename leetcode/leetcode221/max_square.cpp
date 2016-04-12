#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    int local_max_square(vector<int> &v) {
        v.push_back(-1);

        stack<int> st;
        int max_square = 0;

        for (int i = 0; i < v.size(); ++i) {
            while (!st.empty() && v[i]<v[st.top()]) {
                int index = st.top(); st.pop();
                int edge = min(v[index], i-(st.empty()?0:st.top()+1));
                max_square = max(max_square, edge*edge);
            }
            st.push(i);
        }

        return max_square;
    }

    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int> > histo(matrix.size(), vector<int>(matrix[0].size()));
        
        // for (int i = 0; i < matrix.size(); ++i) {
        //     for (int j = 0; j < matrix[i].size(); ++j) {
        //         printf("%c", matrix[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (i == 0) {
                    histo[i][j] = matrix[i][j]-'0';
                } else {
                    if (matrix[i][j] == '0') histo[i][j] = 0;
                    else histo[i][j] = histo[i-1][j]+1;
                }
            }
        }

        // for (int i = 0; i < histo.size(); ++i) {
        //     for (int j = 0; j < histo[i].size(); ++j) {
        //         printf("%d", histo[i][j]);
        //     }
        //     printf("\n");
        // }


        int max_square = 0;
        for (int i = 0; i < histo.size(); ++i) {
            max_square = max(max_square, local_max_square(histo[i]));
        }
        return max_square;
    }
};

int main() {
	char m[][5] = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    // cout << sizeof(m)/sizeof(m[0]) << " " << sizeof(m[0])/sizeof(m[0][0]) << endl;
    vector<vector<char> > v(sizeof(m)/sizeof(m[0]), vector<char>(sizeof(m[0])/sizeof(m[0][0])));

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            v[i][j] = m[i][j];
        }
    }

    Solution sol;
    cout << sol.maximalSquare(v) << endl;
	return 0;
}