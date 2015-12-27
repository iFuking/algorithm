#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Median {
public:
    vector<int> getMaxMedian(vector<int> A, int n, int Q, vector<int> l, vector<int> r, vector<int> k) {
		vector<int> ans;
		for (int i = 0; i < Q; ++i) {
			vector<int> sub_vec;
			for (int j = l[i]; j <= r[i]; ++j) sub_vec.push_back(A[j]);
			sort(sub_vec.begin(), sub_vec.end());
			ans.push_back(sub_vec[(2*sub_vec.size()-1-k[i])/2]);
		}
		return ans;
    }
};

int main()
{
	int A[] = {1, 2, 3, 4, 5};
	vector<int> v_A(A, A+sizeof(A)/sizeof(A[0]));
	int l[] = {0, 1, 2};
	vector<int> v_l(l, l+sizeof(l)/sizeof(l[0]));
	int r[] = {1, 2, 3};
	vector<int> v_r(r, r+sizeof(r)/sizeof(r[0]));
	int k[] = {1, 2, 2};
	vector<int> v_k(k, k+sizeof(k)/sizeof(k[0]));
	Median sol;
	sol.getMaxMedian(v_A, 5, 3, v_l, v_r, v_k);
	return 0;
}