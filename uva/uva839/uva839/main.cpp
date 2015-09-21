/*
1
0 2 0 4
0 3 0 1
1 1 1 1
2 4 4 2
1 6 3 2
*/

#include <iostream>
using namespace std;

int solve(int w)
{
	int wl, dl, wr, dr;
	cin >> wl >> dl >> wr >> dr;
	bool st1 = true, st2 = true;
	if (!wl) st1 = solve(wl);
	if (!wr) st2 = solve(wr);
	w = wl+wr;
	return st1 && st2 && (wl*dl==wr*dr);
}

int main()
{
	int items;
	cin >> items;
	while(items--)
	{
		if (solve(0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}