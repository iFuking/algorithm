#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
		int head = 0, tail = height.size()-1;
		while (head < tail) {
			ans = max(ans, min(height[head], height[tail])*(tail-head));
			if (height[head] < height[tail]) ++head;
			else --tail;
		}
		return ans;
    }
};

int main()
{
	int a[] = {1, 1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	sol.maxArea(v);
	return 0;
}