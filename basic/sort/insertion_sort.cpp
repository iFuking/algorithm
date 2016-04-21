#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void insertion_sort(vector<int> &v) {
	for (int i = 1; i < v.size(); ++i) {
		int tmp = v[i], j;
		for (j = i-1; j>=0 && v[j]>tmp; --j) {
			v[j+1] = v[j];
		}
		v[j+1] = tmp;
	}
	return;
}

void solve() {
	int a[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	insertion_sort(v);

	for (int i = 0; i < v.size(); ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
	return;
}

int main() {
	solve();
	return 0;
}