#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn];

class Solution {
public:
	int char2int(char ch) { return ch-'0'; }

    int numDecodings(string s) {
		if (s[0] == '0') return 0;
		else if (s.length() == 1) return 1;
		else if (s.length() == 2) {
			int num = 10*char2int(s[0])+char2int(s[1]);
			return (s[1]=='0'?0:1) + (num>26?0:1);
 		}

        dp[0] = s[0]=='0' ? 0 : 1;
		int num = 10*char2int(s[0])+char2int(s[1]);
		dp[1] = (s[1]=='0'?0:1) + (num>26?0:1);

		for (int i = 2; i < s.length(); ++i) {
			dp[i] = 0;
			if (s[i] != '0') dp[i] += dp[i-1];
			
			int num = 10*char2int(s[i-1])+char2int(s[i]);
			if (s[i-1]!='0' && num<=26) dp[i] += dp[i-2];
		}
		return dp[s.length()-1];
    }
};

int main()
{
	Solution sol;
	cout << sol.numDecodings("110") << endl;
	return 0;
}