#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int maxScore(vector<vector<int> > &grid){
	int row = grid.size();
	if (row <= 0) return 0;
	int col = grid[0].size();
	if (col <= 0) return 0;
	vector<vector<int> > dp(row, vector<int>(col + 1, 0));
	vector<int> cand1(row, -1);
	vector<int> cand2(row, -1);
	vector<int> cand1_1(row, -1);
	vector<int> cand2_1(row, -1);
	int pre;
	for (int i = 1; i <= col; i++){
		int sum = 0;
		int idx = -1;
		for (int j = 0; j < row; j++){
			if (grid[j][i - 1] == -1){
				cand1[j] = -1;
				continue;
			}
			if (j == 0){
				if (dp[j][i - 1] < 0){    //探测最顶部点是否可达
					cand1[j] = -1;
					for (int s = row - 1; s > 0; s--){
						if (dp[s][i - 1] >= 0 && grid[s][i - 1] >= 0){
							idx = s;
							cand1[j] = grid[j][i - 1];
							cand1_1[j] = -1;
							break;
						}
					}
				}
				else{
					cand1[j] = dp[j][i - 1] + grid[j][i - 1];
					cand1_1[j] = cand1[j];
				}
			}
			else{
				if (j == idx){
					pre = max(cand1_1[j - 1], dp[j][i - 1]);
					cand1[j] = pre < 0 ? -1 : pre + grid[j][i - 1];
				}
				else{
					pre = max(cand1[j - 1], dp[j][i - 1]);
					cand1[j] = pre < 0 ? -1 : pre + grid[j][i - 1];
					pre = max(cand1_1[j - 1], dp[j][i - 1]);
					cand1_1[j] = pre < 0 ? -1 : pre + grid[j][i - 1];
				}
			}
		}
		for (int j = row - 1; j >= 0; j--){
			if (grid[j][i - 1] == -1){
				cand2[j] = -1;
				continue;
			}
			if (j == row - 1){
				if (dp[j][i - 1] < 0){   //探测最底部点是否可达
					cand2[j] = -1;
					for (int s = 0; s < row - 1; s++){
						if (dp[s][i - 1] >= 0 && grid[s][i - 1] >= 0){
							idx = s;
							cand2[j] = grid[j][i - 1];
							cand2_1[j] = -1;
							break;
						}
					}
				}
				else{
					cand2[j] = dp[j][i - 1] + grid[j][i - 1];
					cand2_1[j] = cand2[j];
				}
			}
			else{
				if (j == idx){
					pre = max(cand2_1[j + 1], dp[j][i - 1]);
					cand2[j] = pre < 0 ? -1 : pre + grid[j][i - 1];
				}
				else{
					pre = max(cand2[j + 1], dp[j][i - 1]);
					cand2[j] = pre < 0 ? -1 : pre + grid[j][i - 1];
					pre = max(cand2_1[j + 1], dp[j][i - 1]);
					cand2_1[j] = pre < 0 ? -1 : pre + grid[j][i - 1];
				}
			}
		}
		for (int j = 0; j < row; j++)
			dp[j][i] = max(cand1[j], cand2[j]);
	}
	int ret = 0;
	for (int i = 0; i < row; i++)
		ret = max(ret, dp[i][col]);
	return ret;
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF){
		vector<vector<int> > grid(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				scanf("%d", &grid[i][j]);
			}
		}
		printf("%d\n", maxScore(grid));
	}
	return 0;
}