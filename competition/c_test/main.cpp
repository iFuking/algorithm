#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n); v[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;
        int f2 = 2, f3 = 3, f5 = 5;
        int n2 = v[i2]*f2, n3 = v[i3]*f3, n5 = v[i5]*f5;

        for (int i = 1; i < n; ++i) {
        	v[i] = min(min(n2, n3), n5);

        	if (n2 == v[i]) n2 = v[++i2]*f2;
        	if (n3 == v[i]) n3 = v[++i3]*f3;
        	if (n5 == v[i]) n5 = v[++i5]*f5;
        }

        return v[n-1];
    }
};

int main() {
    Solution sol;
    cout << sol.nthUglyNumber(9) << endl;
    return 0;
}
