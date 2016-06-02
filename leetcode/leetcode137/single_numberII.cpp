#include <iostream>
#include <vector>
using namespace std;

// e.g. 0010 0010 0010 1011 1011 1011 1000 (assuming 4-bit integers) 
// 2(0010) and 11(1011) appeared 3 times, and digit counts are:
// Digits 3 2 1 0
// Counts 4 0 6 3
// Counts%3 1 0 0 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int b = 0; b < 32; ++b) {
        	int bit_sum = 0;
        	for (int i = 0; i < nums.size(); ++i) {
        		bit_sum += (nums[i]&1);
        		nums[i] >>= 1;
        	}
        	ans += ((bit_sum%3)<<b);
        }
        return ans;
    }
};

int main() {
	int a[] = {2, 2, 2, 11, 11, 11, 8};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	cout << sol.singleNumber(v) << endl;
	return 0;
}