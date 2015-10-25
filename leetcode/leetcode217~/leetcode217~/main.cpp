#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0) return false;
		map<int, int> appear_cnt;
		for (int i = 0; i < nums.size(); ++i) {
			++appear_cnt[nums[i]];
			if (appear_cnt[nums[i]] > 1) return true;
		}
		return false;
    }
};

int main()
{
	return 0;
}