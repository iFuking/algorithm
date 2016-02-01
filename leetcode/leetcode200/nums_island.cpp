#include <iostream>
#include <vector>
using namespace std;

const int dir[][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

class Solution {
public:
    void dfs(int x, int y, vector<vector<char> > &grid) {
        grid[x][y] = '0';
        for (int k = 0; k < sizeof(dir)/sizeof(dir[0]); ++k) {
            int dx = x+dir[k][0], dy = y+dir[k][1];
            if (dx>=0 && dx<grid.size() && dy>=0 && dy<grid[0].size() && grid[dx][dy]-'0') {
                dfs(dx, dy, grid);
            }
        }
        return;
    }

    int numIslands(vector<vector<char> >& grid) {
        if (grid.size() < 1) return 0;

        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]-'0') {
                    dfs(i, j, grid);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main()
{
//    char a[4][5] = {
//        {'1', '1', '1', '1', '0'},
//        {'1', '1', '0', '1', '0'},
//        {'1', '1', '0', '0', '0'},
//        {'0', '0', '0', '0', '0'}
//    };
//    char a[4][5] = {
//        {'1', '1', '0', '0', '0'},
//        {'1', '1', '0', '0', '0'},
//        {'0', '0', '1', '0', '0'},
//        {'0', '0', '0', '1', '1'}
//    };
    char a[2][1] = {
        {'1'},
        {'1'}
    };
    vector<vector<char> > v(sizeof(a)/sizeof(a[0]), vector<char>(sizeof(a[0])/sizeof(a[0][0]), '0'));
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        for (int j = 0; j < sizeof(a[0])/sizeof(a[0][0]); ++j) {
            v[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 1; ++j) cout << v[i][j];
        cout << endl;
    }
    Solution sol;
    cout << sol.numIslands(v) << endl;
    return 0;
}
