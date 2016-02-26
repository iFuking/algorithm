#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dir[][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

class Solution {
public:
    int row, col;

    bool bfs(int r, int c, vector<vector<char> >& b, vector<vector<bool> > &v, vector<pair<int, int> > &s) {
        v[r][c] = true;
        bool edge = false;
        if (r==0 || r==row-1 || c==0 || c==col-1) edge = true;
        queue<pair<int, int> > q; q.push(make_pair(r, c));
        while (!q.empty()) {
            pair<int, int> p = q.front(); s.push_back(p); q.pop();
            for (int i = 0; i < sizeof(dir)/sizeof(dir[0]); ++i) {
                int dr = p.first+dir[i][0], dc = p.second+dir[i][1];
                if (dr>=0 && dr<row && dc>=0 && dc<col && b[dr][dc]=='O' && !v[dr][dc]) {
                    if (!edge && (dr==0||dr==row-1||dc==0||dc==col-1)) edge = true;
                    v[dr][dc] = true;
                    q.push(make_pair(dr, dc));
                }
            }
        }
        return edge;
    }

    void solve(vector<vector<char> >& board) {
        if (board.size() < 1) return;
        row = board.size(); col = board[0].size();
        vector<vector<bool> > v(row, vector<bool>(col, false));

//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < col; ++j) cout << board[i][j];
//            cout << endl;
//        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                vector<pair<int, int> > s;
                if (board[i][j]=='O' && !v[i][j] && !bfs(i, j, board, v, s)) {
                    for (int k = 0; k < s.size(); ++k) {
                        board[s[k].first][s[k].second] = 'X';
                    }
                }
            }
        }

//        cout << endl;
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < col; ++j) cout << board[i][j];
//            cout << endl;
//        }

        return;
    }
};

int main() {
    Solution sol;
    char b[][4] = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'O'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    vector<vector<char> > board(sizeof(b)/sizeof(b[0]), vector<char>(sizeof(b[0])/sizeof(b[0][0])));
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) board[i][j] = b[i][j];
    }
    sol.solve(board);
    return 0;
}
