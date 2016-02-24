#include <iostream>
using namespace std;

class Solution {
public:
    int b_search(int left, int right, int x) {
        while (left <= right) {
            long long mid = (left+right) >> 1;
            if (mid*mid < x) left = mid+1;
            else if (mid*mid > x) right = mid-1;
            else return mid;
        }
        return right;
    }

    int mySqrt(int x) {
        return b_search(0, x, x);
    }
};

int main() {
    Solution sol;
    while (true) {
        int x; cin >> x;
        cout << sol.mySqrt(x) << endl;
    }
    return 0;
}
