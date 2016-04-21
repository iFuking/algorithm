#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void bubble_sort(vector<int> &v) {
	for (int i = v.size()-1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (v[j] > v[j+1]) {
				swap(v[j], v[j+1]);
			}
		}
	}
	return;
}

void solve() {
	int a[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	bubble_sort(v);

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