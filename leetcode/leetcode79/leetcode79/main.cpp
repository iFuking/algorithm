#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1e3 + 10;
int dir[][2] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1}
};
vector<char> w;
bool visit[maxn][maxn], is_find;

class Solution {
public:
	void dfs(int row, int col, int index, vector<vector<char>>& board, string &word)
	{
		if (w.size() == word.length()) { is_find = true; return; }
		if (is_find || index==word.size()) return;
		for (int i = 0; i < 4; ++i) {
			int r = row+dir[i][0], c = col+dir[i][1];
			if (r>=0 && r<board.size() && c>=0 && c<board[r].size() && 
				!visit[r][c] && board[r][c]==word[index]) {
				visit[r][c] = true; w.push_back(word[index]);
				dfs(r, c, index+1, board, word);
				visit[r][c] = false; w.pop_back();
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
		if (word.length()==1 && pos.size()>0) return true;

		memset(visit, 0, sizeof(visit)); is_find = false;
		w.push_back(word[0]);
		for (int i = 0; i < pos.size(); ++i) {
			int row = pos[i].first, col = pos[i].second;
			visit[row][col] = true;
			dfs(row, col, 1, board, word);
			visit[row][col] = false;
			if (is_find) return true;
		}
		return false;
    }
};

int main()
{
	char b[][4] = { 
		{'A', 'B', 'C', 'E'}, 
		{'S', 'F', 'C', 'S'}, 
		{'A', 'D', 'E', 'E'}
	};
	char a[][1] = { {'a'} };
	vector<vector<char>> board(1);
	for (int i = 0; i < 1; ++i) {
		for (int j = 0; j < 1; ++j) board[i].push_back(a[i][j]);
	}
	Solution sol;
	cout << sol.exist(board, "ab") << endl;
	return 0;
}

