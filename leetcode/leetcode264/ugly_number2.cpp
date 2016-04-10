#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n); v[0] = 1;
        
        int i2 = 0, i3 = 0, i5 = 0;
        int f2 = 2, f3 = 3, f5 = 5;

        for (int i = 1; i < n; ++i) {
            int n2 = v[i2]*f2, n3 = v[i3]*f3, n5 = v[i5]*f5;
        	v[i] = min(min(n2, n3), n5);

        	if (n2 == v[i]) ++i2;
        	if (n3 == v[i]) ++i3;
        	if (n5 == v[i]) ++i5;
        }

        return v[n-1];
    }
};

int main() {
	Solution sol;
	while (true) {
		int n; cin >> n;
		cout << sol.nthUglyNumber(n) << endl;
	}
	return 0;
}