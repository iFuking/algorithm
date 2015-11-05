#include <iostream>
#include <vector>
using namespace std;

void int2vec(long long n, vector<int> &v)
{
	while (n) {
		v.push_back(n%10);
		n /= 10;
	}
	return;
}

vector<int> reverse_vec(vector<int> &v)
{
	vector<int> ans;
	for (int i = v.size()-1; i >= 0; --i) ans.push_back(v[i]);
	return ans;
}

void vec_plus(vector<int> &v, vector<int> &res_v)
{
	for (int i = 0; i < v.size(); ++i) v[i] += res_v[i];
	for (int i = 0; i < v.size()-1; ++i) {
		v[i+1] += v[i]/10;
		v[i] %= 10;
	}
	int v_size = v.size();
	if (v[v_size-1] > 9) {
		v.push_back(v[v_size-1]/10);
		v[v_size-1] %= 10;
	}
	return;
}

void solve()
{
	long long N; cin >> N;
	int K; cin >> K;

	vector<int> vec_N;
	int2vec(N, vec_N);
	for (int k = 0; k < K; ++k) {
		vector<int> reverse_N = reverse_vec(vec_N);
		if (vec_N == reverse_N) {
			for (int i = vec_N.size()-1; i >= 0; --i) printf("%d", vec_N[i]);
			printf("\n%d\n", k); return;
		}
		vec_plus(vec_N, reverse_N);
	}
	for (int i = vec_N.size()-1; i >= 0; --i) printf("%d", vec_N[i]);
	printf("\n%d\n", K);
	return;
}

int main()
{
	solve();
	return 0;
}

/*
6594871542 100
*/