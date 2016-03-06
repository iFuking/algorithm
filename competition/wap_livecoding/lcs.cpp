#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn][maxn];

string longest_common_substring(const string &s, const string &t) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == t[0]) dp[i][0] = 1;
    }
    for (int j = 0; j < t.length(); ++j) {
        if (s[0] == t[j]) dp[0][j] = 1;
    }

    int max_len = 0, index;
    for (int i = 1; i < s.length(); ++i) {
        for (int j = 1; j < t.length(); ++j) {
            if (s[i] == t[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = 0;
            if (dp[i][j] > max_len) max_len = dp[index=i][j];
        }
    }

    return s.substr(index-max_len+1, max_len);
}

//int main() {
//    string s, t; cin >> s >> t;
//    cout << longest_common_substring(s, t) << endl;
//    return 0;
//}
