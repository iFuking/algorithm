#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void selection_sort(vector<int> &v) {
	for (int i = 0; i < v.size()-1; ++i) {
		int min_num = v[i], flag = i;
		for (int j = i+1; j < v.size(); ++j) {
			if (v[j] < min_num) {
				min_num = v[flag=j];
			}
		}
		swap(v[i], v[flag]);
	}
	return;
}

void solve() {
	int a[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	selection_sort(v);

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