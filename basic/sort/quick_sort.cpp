#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int partition(int left, int right, vector<int> &v) {
	int i = left, j = right;
	int pivot = v[i];
	while (i < j) {
		while (i<j && pivot<=v[j]) --j;
		if (i < j) swap(v[i++], v[j]);
		while (i<j && v[i]<=pivot) ++i;
		if (i < j) swap(v[i], v[j--]);
	}
	return i;
}

void q_sort(int left, int right, vector<int> &v) {
	int pivot;
	if (left < right) {
		pivot = partition(left, right, v);
		q_sort(left, pivot-1, v);
		q_sort(pivot+1, right, v);
	}
	return;
}

void quick_sort(vector<int> &v) {
	q_sort(0, v.size()-1, v);
	return;
}

void solve() {
	int a[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	quick_sort(v);

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