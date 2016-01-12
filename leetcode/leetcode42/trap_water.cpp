#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, level = 0, water = 0;
        while (left < right) {
            int lower = height[height[left]<height[right]?left++:right--];
            level = max(level, lower);
            water += (level-lower);
        }
        return water;
    }
};

int main()
{
	int a[] = {2, 0, 2};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	cout << sol.trap(v) << endl;
	return 0;
}
