#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

void solve() {
    srand((unsigned int)time(NULL));

    FILE *fp = NULL;
    fp = fopen("/home/dick/a.txt", "w");

    for (int n = 1; n <= 10; ++n) {
        for (int m = 1; m <= 10; ++m) {
            for (int p = 2; p <= 6; ++p) {
                fprintf(fp, "%d %d %d\n", n, m, p);

                for (int k = 0; k < p; ++k) {
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                            fprintf(fp, "%d", rand()%2);
                        }
                        fprintf(fp, "\n");
                    }
                    fprintf(fp, "\n");
                }
                fprintf(fp, "\n");
                
            }
        }
    }

    fclose(fp);
    return;
}

int main() {
    solve();
    return 0;
}