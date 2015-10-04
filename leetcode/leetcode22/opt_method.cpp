#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void generateParenthesis(int left_remain, int right_remain, string s, vector<string> &gen) {
		if (left_remain==0 && right_remain==0) { gen.push_back(s); return; }
		if (left_remain > 0) generateParenthesis(left_remain-1, right_remain, s+'(', gen);
		if (right_remain>0 && left_remain<right_remain) generateParenthesis(left_remain, right_remain-1, s+')', gen);
		return;
	}

	vector<string> generateParenthesis(int n) {
		vector<string> gen;
		generateParenthesis(n-1, n, "(", gen);
		// for (int i = 0; i < gen.size(); ++i) printf("%s\n", gen[i].c_str());
		return gen;
	}
};

int main()
{
	Solution sol;
	sol.generateParenthesis(3);
	return 0;
}
