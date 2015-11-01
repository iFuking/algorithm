#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dir[][2] = {
	{0, -1}, {1, 0}, {0, 1}, {-1, 0}
};
vector<char> w;

class Solution {
public:
	void dfs(int row, int col, int index, vector<vector<char>>& board, string &word)
	{
		if (w.size() == word.length()) return;
		for (int i = 0; i < 4; ++i) {
			int r = row+dir[i][0], c = col+dir[i][1];
			if (r>=0 && r<board.size() && c>=0 && c<board[r].size()) {
				w.push_back(word[index+1]);
				dfs(r, c, index+1, board, word);
				w.pop_back();
			}
		}
		return;
	}

    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> pos;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if (board[i][j] == word[0]) pos.push_back(make_pair(i, j));
			}
		}

		w.push_back(word[0]);
		for (int i = 0; i < pos.size(); ++i) dfs(pos[i].first, pos[i].second, 0, board, word);
		return true;
    }
};

int main()
{
	char b[][4] = { 
		{'A', 'B', 'C', 'E'}, 
		{'S', 'F', 'C', 'S'}, 
		{'A', 'D', 'E', 'E'}
	};
	vector<vector<char>> board(3);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) board[i].push_back(b[i][j]);
	}
	Solution sol; sol.exist(board, "ABCCED");
	return 0;
}

