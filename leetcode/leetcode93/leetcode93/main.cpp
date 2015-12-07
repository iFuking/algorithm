#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
	bool pre_zero(string &s)
	{
		if (s == "0") return true;
		if (s[0] == '0') return false;
		return true;
	}

    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
		if (s.length()<4 || s.length()>12) return ips;

		for (int i = 1; i<4 && i<s.length(); ++i) {
			string ip1 = s.substr(0, i);
			if (pre_zero(ip1) && atoi(ip1.c_str())<256) {
				for (int j = 1; j<4 && i+j<s.length(); ++j) {
					string ip2 = s.substr(i, j);
					if (pre_zero(ip2) && atoi(ip2.c_str()) < 256) {
						for (int k = 1; k<4 && i+j+k<s.length(); ++k) {
							string ip3 = s.substr(i+j, k);
							if (pre_zero(ip3) && atoi(ip3.c_str()) < 256) {
								string ip4 = s.substr(i+j+k, s.length()-i-j-k);
								if (pre_zero(ip4) && atoi(ip4.c_str()) < 256) ips.push_back(ip1+'.'+ip2+'.'+ip3+'.'+ip4);
							}
						}
					}
				}
			}
		}
		return ips;
    }
};

int main()
{
	Solution sol;
	sol.restoreIpAddresses("010010");
	return 0;
}