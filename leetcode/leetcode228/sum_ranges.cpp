#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string int2str(long long n)
    {
        if (n == 0) return "0";
        bool sign = n<0 ? true : false;
        n = labs(n);

        string str = "";
        while (n) {
            str += (n%10+'0');
            n /= 10;
        }
        reverse(str.begin(), str.end());
        return sign ? "-"+str : str;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> sum_range;
        if (nums.size() < 1) return sum_range;

        string left, right; int l, r;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) { l = r = nums[0]; continue; }
            if (nums[i] == nums[i-1]+1) r = nums[i];
            else {
                if (l == r) sum_range.push_back(int2str(l));
                else sum_range.push_back(int2str(l)+"->"+int2str(r));
                l = r = nums[i];
            }
        }

        if (l == r) sum_range.push_back(int2str(l));
        else sum_range.push_back(int2str(l)+"->"+int2str(r));
        return sum_range;
    }
};

int main()
{
    int a[] = {0,1,2,4,5,7,9,10,12,14,15,16,27,28};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    vector<string> res = sol.summaryRanges(v);
    for (int i = 0; i < res.size(); ++i) cout << res[i] << endl;
	return 0;
}
