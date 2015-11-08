#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;

	void dfs(vector<int> &v, int index, vector<int> &cur, int sum, int target)
	{
		if (sum > target) return;
		if (sum == target) { ans.push_back(cur); return; }
		for (int i = 0; i < v.size(); ++i) {
			if (i >= index) {
				cur.push_back(v[i]);
				dfs(v, i, cur, sum+v[i], target);
				cur.pop_back();
			}
		}
		return;
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.size() == 0) return ans;
		sort(candidates.begin(), candidates.end());
		vector<int> res;
		dfs(candidates, 0, res, 0, target);
		return ans;
    }
};

int main()
{
	int a[] = {2, 3, 6, 7};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	sol.combinationSum(v, 7);
	return 0;
}