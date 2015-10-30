#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x == 0) return true;

		int divide = log10(1.0*x);
		if (divide == 0) return true;
		else if (divide == 1) return x/10 == x%10;

		divide = pow(10.0, divide);
		while (divide > 0) {
			if (x/divide != x%10) return false;
			x %= divide; x /= 10;
			divide /= 100;
		}
		return true;
    }
};