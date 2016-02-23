#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            int digit_sum = 0;
            while (num) {
                digit_sum += num%10;
                num /= 10;
            }
            num = digit_sum;
        }
        return num;
    }
};

int main() {
    Solution sol;
    while (true) {
        int n; cin >> n;
        cout << sol.addDigits(n) << endl;
    }
    return 0;
}
