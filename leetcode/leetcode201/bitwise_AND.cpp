#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
        	// n&(n-1) remove the right most one
        	n = n&(n-1);
        }
        return n;
    }
};

int main() {
	Solution sol;
	cout << sol.rangeBitwiseAnd(2, 3) << endl;
	return 0;
}