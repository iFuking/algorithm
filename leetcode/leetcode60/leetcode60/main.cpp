#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void swap(char &ch1, char &ch2)
	{
		char ch = ch1; ch1 = ch2; ch2 = ch;
		return;
	}

	bool permutation(string &s)
	{
		for (int i = s.length()-2; i >= 0; --i) {
			int ii = i+1;
			if (s[i] < s[ii]) {
				int j = s.size();
				while (s[i] >= s[--j]) ;
				swap(s[i], s[j]);
				for (int k = 0; k < (s.size()-ii)/2; ++k) {
					swap(s[ii+k], s[s.size()-1-k]);
				}
				return true;
			}
		}
		return false;
	}

	int fac(int n)
	{
		if (n == 1) return 1;
		return n*fac(n-1);
	}

    string getPermutation(int n, int k) {
        string s = "";
		if (k > fac(n)) return s;

		for (int i = 1; i <= n; ++i) s += i+'0';
		if (k == 1) return s;
		for (int i = 2; permutation(s); ++i) {
			if (i == k) break;
		}
		return s;
    }
};

int main()
{
	Solution sol;
	cout << sol.getPermutation(8, 8590) << endl;
	return 0;
}