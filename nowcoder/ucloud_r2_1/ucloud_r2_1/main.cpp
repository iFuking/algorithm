#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double esp = 1e-6;

class LineAndCircle {
public:
    int judgeStat(int x1, int y1, int x2, int y2, int xc, int yc, int r) {
		int A = y2-y1, B = x1-x2, C = x2*y1-x1*y2;
		double d = fabs(A*xc+B*yc+C+0.0) / sqrt(A*A+B*B+0.0);
		if (fabs(d-r) < esp) return 1;
		else if (d > r) return 0;
		return 2;
    }
};

int main()
{
	int arr[] = {-1, -1, 1, 1, 0, 0, 2};
	vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
	LineAndCircle sol;
	cout << sol.judgeStat(-1, -1, 1, 1, 0, 0, 2) << endl;
	return 0;
}