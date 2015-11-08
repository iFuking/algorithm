#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	set<vector<int>> dup;

	void dfs(vector<int> &v, int index, vector<int> &cur, int sum, int target)
	{
		if (sum > target) return;
		else if (sum == target) { ans.push_back(cur); return; }
		for (int i = 0; i < v.size(); ++i) {
			if (i > index) {
				cur.push_back(v[i]);
				dfs(v, i, cur, sum+v[i], target);
				cur.pop_back();
				while (i<v.size()-1 && v[i]==v[i+1]) ++i;
			}
		}
		return;
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.size() == 0) return ans;
		sort(candidates.begin(), candidates.end());
		vector<int> res;
		dfs(candidates, -1, res, 0, target);
		return ans;
    }
};

int main()
{
	int a[] = {10, 1, 2, 7, 6, 1, 5};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	sol.combinationSum2(v, 8);
	return 0;
}