#include <iostream>
using namespace std;

void solve()
{
	int N; cin >> N;
	int position = 0, total_time = 0;
	for (int i = 0; i < N; ++i)
	{
		int flo; scanf("%d", &flo);
		if (position < flo) total_time += (flo-position)*6;
		else if (position > flo) total_time += (position-flo)*4;
		total_time += 5;
		position = flo;
	}
	cout << total_time << endl;
	return;
}

int main()
{
	solve();
	return 0;
}