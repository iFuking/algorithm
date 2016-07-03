#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = (left+right) >> 1;
            if (citations[mid] < n-mid) left = mid+1;
            else right = mid-1;
        }
        return n-left;
    }
};

int main() {
    Solution sol;
    int a[] = {1};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    cout << sol.hIndex(v) << endl;
    return 0;
}