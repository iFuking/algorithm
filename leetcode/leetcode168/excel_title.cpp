#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            s += ((n-1)%26+'A');
            n = (n-1)/26;
        }
        for (int i = 0; i < s.length()/2; ++i) swap(s[i], s[s.length()-1-i]);
        return s;
    }
};

int main()
{
    Solution sol;
    while (true) {
        int n; cin >> n;
        cout << sol.convertToTitle(n) << endl;
    }
    return 0;
}
