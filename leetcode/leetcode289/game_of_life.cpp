#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int dir[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
        {1, 1}, {1, 0}, {1, -1}, {0, -1}
    };

    int num_of_live_neighbors(int x, int y, vector<vector<int> >& board)
    {
        int numbers = 0;
        for (int i = 0; i < sizeof(dir)/sizeof(dir[0]); ++i) {
            int dx = x+dir[i][0];
            int dy = y+dir[i][1];
            if (dx>=0 && dx<board.size() && dy>=0 && dy<board[0].size()) {
                if (1 == board[dx][dy]) ++numbers;
            }
        }
        return numbers;
    }

    int rule(int x, int y, vector<vector<int> >& board)
    {
        int live_neighbors = num_of_live_neighbors(x, y, board);
        if (board[x][y]==1 && live_neighbors<2) return 0;
        else if (board[x][y]==1 && (live_neighbors==2||live_neighbors==3)) return 1;
        else if (board[x][y]==1 && live_neighbors>3) return 0;
        else if (board[x][y]==0 && live_neighbors==3) return 1;
        return 0;
    }

    void gameOfLife(vector<vector<int> >& board) {
        vector<vector<int> > update(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                update[i][j] = rule(i, j, board);
            }
        }
        board = update;
    }
};

int main()
{
	int a[][2] = {{1, 1}, {1, 0}};
	vector<vector<int> > v(sizeof(a)/sizeof(a[0]), vector<int>(sizeof(a[0])/sizeof(a[0][0]), 0));
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        for (int j = 0; j < sizeof(a[0])/sizeof(a[0][0]); ++j) {
            v[i][j] = a[i][j];
        }
	}
	Solution sol;
	sol.gameOfLife(v);
	return 0;
}
