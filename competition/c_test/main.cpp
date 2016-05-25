#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void merge(vector<int> &v1, vector<int> &v2, vector<int> &v) {
	int i = 0, j = 0;
	while (i<v1.size() && j<v2.size()) {
		if (v1[i] < v2[j]) ++i;
		else ++j;
		v.push_back(min(v1[i], v2[j]));
	}

	if (i == v1.size()) {
		while (j < v2.size()) {
			v.push_back(v2[j++]);
		}
	}
	if (j == v2.size()) {
		while (i < v1.size()) {
			v.push_back(v1[i++]);
		}
	}
	return;
}

vector<int> partition(int left, int right, vector<int> &v) {
	if (left == right) return vector<int>(1, v[left]);

	int mid = (left+right) >> 1;
	vector<int> left_part = partition(left, mid, v);
	vector<int> right_part = partition(mid+1, right, v);

	vector<int> sorted;
	merge(left_part, right_part, sorted);

	return sorted;
}

void merge_sort(vector<int> &v) {
	v = partition(0, v.size()-1, v);
	return;
}

void solve() {
	int a[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	merge_sort(v);

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
