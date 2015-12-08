#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> zz(numRows);
		for (int i = 0; i < s.length(); ) {
			for (int r = 0; r<numRows && i<s.length(); ++r) zz[r] += s[i++];
			for (int r = numRows-2; r>0 && i<s.length(); --r) zz[r] += s[i++];
		}

		string ans = "";
		for (int i = 0; i < zz.size(); ++i) ans += zz[i];
		return ans;
    }
};

int main()
{
	Solution sol;
	sol.convert("PAYPALISHIRING", 3);
	return 0;
}