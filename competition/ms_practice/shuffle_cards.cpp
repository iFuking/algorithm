#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void shuffle_cards(int n, vector<int> &v) {
	if (n == 0) return;

	int index = rand() % n;
	swap(v[index], v[n-1]);
	shuffle_cards(n-1, v);
	return;
}

void shuffle() {
	srand((unsigned int)time(NULL));

	int n = 52;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = i+1;
	}

	shuffle_cards(n, v);

	for (int i = 0; i < v.size(); ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
	return;
}

void solve() {
	shuffle();
	return;
}

int main() {
	solve();
	return 0;
}