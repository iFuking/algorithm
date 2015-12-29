#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
//        map<int, int> ele_cnt;
//        for (int i = 0; i < nums.size(); ++i) ++ele_cnt[nums[i]];
//        map<int, int>::iterator iter = ele_cnt.begin();
//        int majo_cnt = -1, majo_ele;
//        for ( ; iter != ele_cnt.end(); ++iter) {
//            if (iter->second > majo_cnt) {
//                majo_cnt = iter->second;
//                majo_ele = iter->first;
//                if (majo_cnt > nums.size()/2) break;
//            }
//        }
//        return majo_ele;
        int majo_ele, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt == 0) { majo_ele = nums[i]; cnt = 1; }
            else if (nums[i] == majo_ele) ++cnt;
            else --cnt;
        }
        return majo_ele;
    }
};

int main()
{
    int a[] = {1, 1, 1, 2, 3};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.majorityElement(v) << endl;
    return 0;
}
