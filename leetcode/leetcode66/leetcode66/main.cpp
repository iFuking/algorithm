#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void swap(int &d1, int &d2)
	{
		int d = d1; d1 = d2; d2 = d;
		return;
	}

    vector<int> plusOne(vector<int>& digits) {
		for (int i = 0; i < digits.size()/2; ++i) {
			swap(digits[i], digits[digits.size()-1-i]);
		}
		digits[0] += 1;

		for (int i = 0; i < digits.size()-1; ++i) {
			digits[i+1] += digits[i]/10;
			digits[i] %= 10;
		}
		if (digits[digits.size()-1] > 9) {
			digits[digits.size()-1] %= 10;
			digits.push_back(1);
		}

		for (int i = 0; i < digits.size()/2; ++i) {
			swap(digits[i], digits[digits.size()-1-i]);
		}
		return digits;
    }
};

int main()
{
	int a[] = {9, 9, 9};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	sol.plusOne(v);
	return 0;
}