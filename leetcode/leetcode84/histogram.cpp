#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> st; int max_area = 0;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[st.top()]>height[i]) {
                int idx = st.top(); st.pop();
                max_area = max(max_area, height[idx]*(i-(st.empty()?0:st.top()+1)));
            }
            st.push(i);
        }
        return max_area;
    }
};

int main()
{
	int a[] = {2, 1, 2};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	cout << sol.largestRectangleArea(v) << endl;
	return 0;
}
