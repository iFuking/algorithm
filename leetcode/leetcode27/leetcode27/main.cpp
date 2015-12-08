#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0) return 0;
		vector<int>::iterator iter = nums.begin();
		while (iter != nums.end()) {
			if (*iter == val) iter = nums.erase(iter);
			else ++iter;
		}
		return nums.size();
    }
};