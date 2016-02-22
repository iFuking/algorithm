#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while (n != 1) {
            s.insert(n);
            int digit_sum = 0, n_copy = n;
            while (n_copy) {
                digit_sum += (n_copy%10)*(n_copy%10);
                n_copy /= 10;
            }
            n = digit_sum;
            if (s.find(n) != s.end()) return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    while (true) {
        int n; cin >> n;
        cout << sol.isHappy(n) << endl;
    }
    return 0;
}
