#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &i1, const Interval &i2)
{
    if (i1.start != i2.start) return i1.start < i2.start;
    return i1.end > i2.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.size() < 1) return ans;
        sort(intervals.begin(), intervals.end(), cmp);

        Interval interval; interval = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].end<=interval.end || intervals[i].start==intervals[i-1].start) continue;
            if (intervals[i].start <= interval.end) interval.end = max(interval.end, intervals[i].end);
            else { ans.push_back(interval); interval = intervals[i]; }
        }
        ans.push_back(interval);
        return ans;
    }
};

int main()
{
	Interval a[] = {{2, 3}, {5, 5}, {2, 2}, {3, 4}, {3, 4}};
	vector<Interval> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    vector<Interval> ans = sol.merge(v);
    for (int i = 0; i < ans.size(); ++i) cout << ans[i].start << ", " << ans[i].end << endl;
	return 0;
}
