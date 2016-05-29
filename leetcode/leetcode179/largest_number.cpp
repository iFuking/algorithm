#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

// bool cmp(const string &s1, const string &s2) {
//     return s1+s2 < s2+s1;
// }

class Solution {
public:
    class cmp {
    public:
        bool operator()(const string &s1, const string &s2) {
            return s1+s2 > s2+s1;
        }
    };

    string to_str(int n) {
        if (n == 0) return "0";
        string s;

        while (n) {
            s += (n%10+'0');
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string rm_head_zero(string s) {
        int idx = 0;
        while (idx<s.length() && s[idx]=='0') ++idx;
        if (idx == s.length()) return "0";
        return s.substr(idx);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.push_back(to_str(nums[i]));
        }

        sort(s.begin(), s.end(), cmp());

        string largest;
        for (int i = 0; i < s.size(); ++i) {
            largest += s[i];
        }
        return rm_head_zero(largest);
    }
};

int main() {
    int a[] = {3, 30, 34, 5, 9};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.largestNumber(v) << endl;
    return 0;
}