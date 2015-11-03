#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &m, const pair<int, int> &n) {
	if (m.second != n.second) return m.second < n.second;
	return m.first < n.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<pair<int, int>> nodes;
		for (int i = 0; i < nums.size(); ++i) nodes.push_back(make_pair(i+1, nums[i]));
		sort(nodes.begin(), nodes.end(), cmp);

		vector<int> ans;
		int head = 0, tail = nodes.size()-1;
		while (head < tail) {
			int two_sum = nodes[head].second+nodes[tail].second;
			if (two_sum < target) ++head;
			else if (two_sum > target) --tail;
			else {
				ans.push_back(min(nodes[head].first, nodes[tail].first));
				ans.push_back(max(nodes[head].first, nodes[tail].first));
				break;
			}
		}
		return ans;
    }
};

int main()
{
	int num[] = {2, 7, 11, 15};
	vector<int> number(num, num+4);
	Solution sol;
	sol.twoSum(number, 9);
	return 0;
}