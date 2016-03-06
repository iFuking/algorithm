#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxm = 777;
const int maxn = 999;
const int value = 1e5 - 3;
const int block = 1;
int grid[maxm][maxn];

int main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxm; ++i) {
		for (int j = 0; j < maxn; ++j) grid[i][j] = rand()%value;
	}

	for (int i = 0; i < block; ++i) {
		int x = rand()%maxm;
		int y = rand()%maxn;
		grid[x][y] = -1;
	}

	FILE *fp = NULL;
	fp = fopen("../../wap201510/ex1_testcase.txt", "w");
	fprintf(fp, "%d %d\n", maxm, maxn);
	for (int i = 0; i < maxm; ++i) {
		for (int j = 0; j < maxn; ++j) fprintf(fp, "%d ", grid[i][j]);
		fprintf(fp, "\n");
	}
	return 0;
}