#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e6 + 10;

//class Solution {
//public:
//    int step[maxn];
//
//    int jump(vector<int>& nums) {
//        step[nums.size()-1] = 0;
//        for (int i = nums.size()-2; i >= 0; --i) {
//            int min_step = nums.size();
//            for (int j = i+1; j<nums.size() && j<i+1+nums[i]; ++j) {
//                if (step[j] < min_step) min_step = step[j];
//            }
//            step[i] = min_step+1;
//        }
//        return step[0];
//    }
//};

class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0, j_right = 0, r_most = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            r_most = max(r_most, i+nums[i]);
            if (i == j_right) {
                ++jump;
                j_right = r_most;

                if (r_most >= nums.size()-1) break;
            }
        }
        return jump;
    }
};

int main()
{
	int a[] = {1, 1, 1, 1, 1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	cout << sol.jump(v) << endl;
	return 0;
}
