#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void heap_push(int n, vector<int> &v) {
	int i = v.size(); v.push_back(n);
	while (i/2>=1 && v[i]<v[i/2]) {
		swap(v[i], v[i/2]);
		i /= 2;
	}
	return;
}

int heap_pop(vector<int> &v) {
	int i = 1, top = v[1], n = v.size();
	while (2*i+1 < n) {
		if (v[2*i] < v[2*i+1]) {
			swap(v[i], v[2*i]);
			i = 2*i;
		} else {
			swap(v[i], v[2*i+1]);
			i = 2*i+1;
		}
	}
	swap(v[i], v[n-1]);
	v.pop_back();
	return top;
}

void heap_sort(vector<int> &v) {
	vector<int> h; h.push_back(0);
	for (int i = 0; i < v.size(); ++i) {
		heap_push(v[i], h);
	}

	for (int i = 0; i < v.size(); ++i) {
		v[i] = heap_pop(h);
	}
	return;
}

void solve() {
	int a[] = {3, 2, 1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	heap_sort(v);

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