#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxn = 20;
const int value = 97;
const int block = 60;
int grid[maxn][maxn];

int main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxn; ++j) grid[i][j] = rand()%value;
	}

	for (int i = 0; i < block; ++i) {
		int x = rand()%maxn;
		int y = rand()%maxn;
		grid[x][y] = -1;
	}

	FILE *fp = NULL;
	fp = fopen("../../wap201510/ex1_testcase.txt", "w");
	fprintf(fp, "%d %d\n", maxn, maxn);
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxn; ++j) fprintf(fp, "%d ", grid[i][j]);
		fprintf(fp, "\n");
	}
	return 0;
}