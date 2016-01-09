#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int s_index = -1, e_index = -1;
        for (int i = 0; i < intervals.size(); ++i) {
            if (s_index==-1 && newInterval.start<intervals[i].start) s_index = 2*i;
            else if (s_index==-1 && newInterval.start<=intervals[i].end) s_index = 2*i+1;
            if (e_index==-1 && newInterval.end<intervals[i].start) e_index = 2*i;
            else if (e_index==-1 && newInterval.end<=intervals[i].end) e_index = 2*i+1;
        }

        vector<Interval> ans;
        if (s_index == -1) {
            for (int i = 0; i < intervals.size(); ++i) ans.push_back(intervals[i]);
            ans.push_back(newInterval);
        } else if (e_index == -1) {
            if (s_index % 2) {
                for (int i = 0; i < s_index/2; ++i) ans.push_back(intervals[i]);
                ans.push_back({intervals[s_index/2].start, newInterval.end});
            } else {
                for (int i = 0; i < s_index/2; ++i) ans.push_back(intervals[i]);
                ans.push_back(newInterval);
            }
        } else {
            for (int i = 0; i < s_index/2; ++i) ans.push_back(intervals[i]);

            if (s_index%2 && e_index%2) ans.push_back({intervals[s_index/2].start, intervals[e_index/2].end});
            else if (s_index%2 && !(e_index%2)) ans.push_back({intervals[s_index/2].start, newInterval.end});
            else if (!(s_index%2) && e_index%2) ans.push_back({newInterval.start, intervals[e_index/2].end});
            else ans.push_back(newInterval);

            for (int i = e_index/2+e_index%2; i < intervals.size(); ++i) ans.push_back(intervals[i]);
        }
        return ans;
    }
};

int main()
{
	Interval a[] = {{1, 2}, {4, 5}, {7, 8}, {10, 11}, {13, 14}};
	vector<Interval> v(a, a+sizeof(a)/sizeof(a[0]));
	Interval b = Interval(6, 10);
    Solution sol;
    vector<Interval> ans = sol.insert(v, b);
    for (int i = 0; i < ans.size(); ++i) cout << ans[i].start << ", " << ans[i].end << endl;
	return 0;
}
