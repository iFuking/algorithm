#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		if (s.length() == 0) return true;
		vector<char> str;
		for (int i = 0; i < s.length(); ++i) {
			if (isalnum(s[i])) str.push_back(tolower(s[i]));
		}
		for (int i = 0; i < str.size()/2; ++i) {
			if (str[i] != str[str.size()-1-i]) return false;
		}
		return true;
    }
};

int main()
{
	Solution sol;
	sol.isPalindrome("race a car");
	return 0;
}