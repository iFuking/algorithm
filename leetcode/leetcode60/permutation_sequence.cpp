#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        fac[0] = 1;
        for (int i = 1; i < maxn; ++i) {
            fac[i] = i*fac[i-1];
        }

        if (k%fac[n] == 0) {
            --k; k %= fac[n];
        } else {
            k = k%fac[n]-1;
        }

        int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<char> v(a, a+sizeof(a)/sizeof(a[0]));
        string s;

        for (int i = n-1; i >= 0; --i) {
            int index = k/fac[i];
            k %= fac[i];
            s += (v[index]+'0');
            v.erase(v.begin()+index);
        }
        return s;
    }

private:
    static const int maxn = 10;
    int fac[maxn];
};

int main() {
    Solution sol;
    while (true) {
        int n, k; cin >> n >> k;
        cout << sol.getPermutation(n, k) << endl;
    }
    return 0;
}