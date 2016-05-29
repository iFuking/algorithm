#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, min(citations[i], n-i));
        }
        return ans;
    }
};

int main() {
    int a[] = {100};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.hIndex(v) << endl;
    return 0;
}