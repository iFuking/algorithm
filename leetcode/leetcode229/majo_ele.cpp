#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1, n2, c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (c1>0 && nums[i]==n1) { ++c1; continue; }
            if (c2>0 && nums[i]==n2) { ++c2; continue; }
            if (c1 == 0) { n1 = nums[i]; ++c1; continue; }
            if (c2 == 0) { n2 = nums[i]; ++c2; continue; }
            --c1; --c2;
        }

        int t1 = 0, t2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (c1>0 && nums[i]==n1) ++t1;
            if (c2>0 && nums[i]==n2) ++t2;
        }

        vector<int> majo_ele;
        if (t1 > nums.size()/3) majo_ele.push_back(n1);
        if (t2 > nums.size()/3) majo_ele.push_back(n2);

        return majo_ele;
    }
};

int main()
{
    int a[] = {0, -1, 2, -1};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    vector<int> majo_ele = sol.majorityElement(v);
    for (int i = 0; i < majo_ele.size(); ++i) cout << majo_ele[i] << endl;
	return 0;
}
