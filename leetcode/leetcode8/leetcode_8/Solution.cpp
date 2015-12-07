#include "Solution.h"

class Solution {
public:
    int myAtoi(string str) {
		int sign = 1; long long number = 0;
		bool is_start = false;
		vector<int> digit;
		for (int i = 0; i < str.length(); ++i) {
			if (!is_start && isspace(str[i])) continue;
			if (!is_start && str[i]=='-') { sign = -1; is_start = true; continue; }
			else if (!is_start && str[i]=='+') { is_start = true; continue; }
			if (!isdigit(str[i])) break;
			is_start = true;
			number = 10*number+(str[i]-'0');
			if (sign*number < INT_MIN) return INT_MIN;
			else if (sign*number > INT_MAX) return INT_MAX;
		}
		return (int)(sign*number);
    }
};

int main() {
	Solution sol;
	cout << sol.myAtoi("    10522545459") << endl;
	return 0;
}