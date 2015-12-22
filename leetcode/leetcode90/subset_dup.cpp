#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > results;

    void dfs(vector<int>& nums, int index, vector<int>& res)
    {
        results.push_back(res);
        for (int i = index+1; i < nums.size(); ++i) {
            res.push_back(nums[i]);
            dfs(nums, i, res);
            res.pop_back();
            while (i+1<nums.size() && nums[i]==nums[i+1]) ++i;
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res; dfs(nums, -1, res);
        return results;
    }
};

int main()
{
    Solution sol;
    int a[] = {1, 2, 2, 3};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    sol.subsetsWithDup(v);
    return 0;
}
