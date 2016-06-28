#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    string int2str(int n) {
        if (n == 0) return "0";

        string s;
        while (n) {
            s += n%10+'0';
            n /= 10;
        }
        reverse(s.begin(), s.end());

        return s;
    }

    string getHint(string secret, string guess) {
        map<int, int> cnt;
        for (int i = 0; i < secret.length(); ++i) {
            ++cnt[secret[i]-'0'];
        }

        int bulls = 0, cows = 0;
        for (int i = 0; i < guess.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
                --cnt[guess[i]-'0'];
            }
        }
        for (int i = 0; i < guess.length(); ++i) {
            if (secret[i]!=guess[i] && cnt[guess[i]-'0'] > 0) {
                ++cows;
                --cnt[guess[i]-'0'];
            }
        }

        return int2str(bulls)+'A'+int2str(cows)+'B';
    }
};

int main() {
    Solution sol;
    while (true) {
        string s1, s2; cin >> s1 >> s2;
        cout << sol.getHint(s1, s2) << endl;
    }
    return 0;
}