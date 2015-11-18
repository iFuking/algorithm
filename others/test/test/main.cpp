#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		if (s.length() == 0) return true;
		int head = 0, tail = s.length()-1;
		while (head < tail) {
		    while (head<tail && !isalnum(s[head])) ++head;
		    while (head<tail && !isalnum(s[tail])) --tail;
		    if (tolower(s[head]) != tolower(s[tail])) return false;
		    ++head; --tail;
		}
		return true;
    }
};

int main()
{
	Solution sol;
	sol.isPalindrome("abba");
	return 0;
}