#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

char spell[][8] = {
	"zero", "one", "two", "three", "four", 
	"five", "six", "seven", "eight", "nine"
};

void swap(int &ch1, int &ch2)
{
	int tmp = ch1;
	ch1 = ch2;
	ch2 = tmp;
	return;
}

void num2str(int n, vector<int> &v)
{
	while (n > 0)
	{
		v.push_back(n%10);
		n /= 10;
	}
	for (int i = 0; i < v.size()/2; ++i) swap(v[i], v[v.size()-1-i]);
	return;
}

void solve()
{
	string read; cin >> read;
	int sum = 0;
	for (int i = 0; i < read.length(); ++i) sum += (read[i]-'0');
	if (sum == 0) { printf("zero\n"); return; }
	vector<int> v; num2str(sum, v);
	for (int i = 0; i < v.size()-1; ++i) printf("%s ", spell[v[i]]);
	printf("%s\n", spell[v[v.size()-1]]);
	return;
}

int main()
{
	solve();
	return 0;
}