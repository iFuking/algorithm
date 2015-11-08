#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;

	void dfs(int num, vector<int> &cur, int sum, int k, int n)
	{
		if (cur.size()>k || sum>n) return;
		else if (cur.size()==k && sum==n) { ans.push_back(cur); return; }
		for (int i = num+1; i < 10; ++i) {
			cur.push_back(i);
			dfs(i, cur, sum+i, k, n);
			cur.pop_back();
		}
		return;
	}

    vector<vector<int>> combinationSum3(int k, int n) {
		if (k == 0) return ans;
		vector<int> res;
		dfs(0, res, 0, k, n);
		return ans;
    }
};

int main()
{
	Solution sol;
	sol.combinationSum3(3, 9);
	return 0;
}