#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int kth_largest(vector<int> &v, int k) {
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < v.size(); ++i) {
		if (pq.size() < k) pq.push(v[i]);
		else {
			if (v[i] > pq.top()) {
				pq.pop();
				pq.push(v[i]);
			}
		}
	}

	// while (!pq.empty()) {
	// 	printf("%d ", pq.top());
	// 	pq.pop();
	// }
	// printf("\n");

	int pq_size = pq.size();
	vector<int> h(pq_size, 0);
	for (int i = 0; !pq.empty(); ++i) {
		h[pq_size-1-i] = pq.top();
		pq.pop();
	}
	return h[k-1];
}

void solve() {
	priority_queue<int, vector<int>, less<int> > pq;
	int a[] = {220, 14, 73, 19, 1, 3, 100, 55, 12, 7, 100, 44, 99};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	while (true) {
		int k; scanf("%d", &k);
		printf("%d\n", kth_largest(v, k));
	}
	return;
}

int main() {
	solve();
	return 0;
}