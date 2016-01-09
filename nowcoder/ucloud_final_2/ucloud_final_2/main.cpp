#include <iostream>
#include <vector>
using namespace std;

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
		int left_sum = 0, right_sum = 0;
		for (int i = 0; i < left.size(); ++i) {
			left_sum += left[i]; right_sum += right[i];
		}
		
		int left_nums = 0, right_nums = 0;
		int left_min = left_sum+1, right_min = right_sum+1;
		for (int i = 0; i < left.size(); ++i) {
			if (right[i] == 0) left_nums += left[i];
			if (left[i]!=0 && right[i]!=0 && right[i]<right_min) right_min = right[i];

			if (left[i] == 0) right_nums += right[i];
			if (left[i]!=0 && right[i]!=0 && left[i]<left_min) left_min = left[i];
		}

		return min(left_nums+1+right_sum-right_min+1, right_nums+1+left_sum-left_min+1);
    }
};

int main()
{
	int a[] = {0, 7, 1, 6};
	int b[] = {1, 5, 0, 6};
	vector<int> l(a, a+sizeof(a)/sizeof(a[0]));
	vector<int> r(b, b+sizeof(b)/sizeof(b[0]));
	Gloves sol;
	cout << sol.findMinimum(4, l, r) << endl;
	return 0;
}