#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans;
        if ((numerator<0) ^ (denominator<0)) {
            ans += '-';
        }
        long long num = abs((long long)numerator), den = abs((long long)denominator);

        ans += to_string(num/den);
        if (num % den == 0) {
            return ans;
        }

        ans += '.';

        unordered_map<long long, int> umap;  // remainder's position
        for (long long r = num%den; r; r %= den) {
            if (umap.find(r) != umap.end()) {
                ans.insert(umap[r], "(");
                ans += ')';
                break;
            }
            umap[r] = ans.length();
            r *= 10;
            ans += to_string(r/den);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    while (true) {
        int n, d; cin >> n >> d;
        cout << sol.fractionToDecimal(n, d) << endl;
    }
    return 0;
}