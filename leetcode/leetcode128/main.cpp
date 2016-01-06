#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//
//        int cnt = 0, max_cnt = 0;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (i>0 && nums[i]==nums[i-1]) continue;
//            if (i==0 || i>0&&nums[i]==nums[i-1]+1) {
//                ++cnt;
//                if (cnt > max_cnt) max_cnt = cnt;
//            } else cnt = 1;
//        }
//        return max_cnt;
//    }
//};

//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        priority_queue<int, vector<int>, greater<int> > pq;
//        for (int i = 0; i < nums.size(); ++i) pq.push(nums[i]);
//
//        int cnt = 0, max_cnt = 0, pre;
//        while (!pq.empty()) {
//            if (pq.size()<nums.size() && pq.top()==pre) { pq.pop(); continue; }
//            if (pq.size()==nums.size() || pq.size()<nums.size()&&pq.top()==pre+1) {
//                ++cnt;
//                if (cnt > max_cnt) max_cnt = cnt;
//            } else cnt = 1;
//            pre = pq.top();
//            pq.pop();
//        }
//        return max_cnt;
//    }
//};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int ans = 0;

        while (!s.empty()) {
            int val = *s.begin(), k = val+1, len = 1;
            s.erase(val);

            while (s.find(k) != s.end()) { ++len; s.erase(k++); }

            k = val-1;
            while (s.find(k) != s.end()) { ++len; s.erase(k--); }

            ans = max(ans, len);
        }
        return ans;
    }
};

int main()
{
	int a[] = {0, 2, 1, 1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	cout << sol.longestConsecutive(v) << endl;
	return 0;
}
