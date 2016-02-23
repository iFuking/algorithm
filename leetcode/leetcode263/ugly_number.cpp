#include <iostream>
using namespace std;

const int fac[] = {2, 3, 5};

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        for (int i = 0; i < sizeof(fac)/sizeof(fac[0]); ++i) {
            while (num % fac[i] == 0) num /= fac[i];
        }
        return num <= 1;
    }
};

int main() {
    Solution sol;
    while (true) {
        int n; cin >> n;
        cout << sol.isUgly(n) << endl;
    }
    return 0;
}
