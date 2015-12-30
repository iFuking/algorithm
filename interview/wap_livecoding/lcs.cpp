#include <iostream>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn][maxn];

string longest_common_substring(string &s, string &t)
{
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == t[0]) dp[i][0] = 1;
    }
    for (int i = 0; i < t.length(); ++i) {
        if (s[0] == t[i]) dp[0][i] = 1;
    }

    int index, maxlen = 0;
    for (int i = 1; i < s.length(); ++i) {
        for (int j = 1; j < t.length(); ++j) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
                if (dp[i][j] > maxlen) maxlen = dp[index=i][j];
            }
        }
    }
    return s.substr(index-maxlen+1, maxlen);
}

//int main()
//{
//    string s, t; cin >> s >> t;
//    cout << longest_common_substring(s, t) << endl;
//    return 0;
//}
