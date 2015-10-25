#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() == 0) return false;

		map<int, vector<int>> appear_pos;
		for (int i = 0; i < nums.size(); ++i) appear_pos[nums[i]].push_back(i);

		map<int, vector<int>>::iterator iter = appear_pos.begin();
		for ( ; iter != appear_pos.end(); ++iter) {
			if (iter->second.size() > 1) {
				for (int i = 0; i < appear_pos[iter->first].size()-1; ++i) {
					if (appear_pos[iter->first][i+1]-appear_pos[iter->first][i] <= k) return true;
				}
			}
		}
		return false;
    }
};