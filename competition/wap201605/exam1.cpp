#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

const int maxm = 11;
int n, m, p;
vector<string> s;
vector<vector<int> > index;

void dfs(int total, int cur, vector<int> &idx) {
    if (idx.size() == total) {
        index.push_back(idx);
        return;
    }

    for (int i = cur+1; i < n*m; ++i) {
        idx.push_back(i);
        dfs(total, i, idx);
        idx.pop_back();
    }
    return;
}

void build_index(int total) {
    index = vector<vector<int> >();

    vector<int> idx;
    for (int i = 0; i < n*m; ++i) {
        idx.push_back(i);
        dfs(total, i, idx);
        idx.pop_back();
    }
    return;
}

bool meet(int total) {
    build_index(total);

    for (int i = 0; i < index.size(); ++i) {
        vector<string> pix;
        for (int j = 0; j < s.size(); ++j) {
            string str;
            for (int k = 0; k < index[i].size(); ++k) {
                str += s[j][index[i][k]];
            }
            pix.push_back(str);
        }

        bool flag = false;
        for (int j = 0; j < pix.size(); ++j) {
            for (int k = j+1; k < pix.size(); ++k) {
                if (pix[j] == pix[k]) {
                    flag = true;
                    goto failed;
                }
            }
        }
    failed:
        if (!flag) return true; 
    }
    return false;
}

void case4() {
    if (meet(2)) printf("2\n");
    else printf("3\n");
    return;
}

void case5() {
    if (meet(3)) printf("3\n");
    else printf("4\n");
    return;
}

void case6() {
    if (meet(3)) printf("3\n");
    else if (meet(4)) printf("4\n");
    else printf("5\n");
    return;
}

void solve1() {
    FILE *fp = NULL;
    fp = fopen("/home/dick/a.txt", "r");
    while (!feof(fp)) {
        fscanf(fp, "%d %d %d", &n, &m, &p);
        s = vector<string>();
        index = vector<vector<int> >();

        char line[maxm];
        for (int k = 0; k < p; ++k) {
            string str;
            for (int i = 0; i < n; ++i) {
                fscanf(fp, "%s", line);
                str += line;
            }
            s.push_back(str);
        }

        if (p==2 || p==3) {
            printf("%d\n", p-1);
            continue;
        }

        if (p == 4) case4();
        else if (p == 5) case5();
        else case6();
    }
    return;
}

void solve() {
    cin >> n >> m >> p;

    char line[maxm];
    for (int k = 0; k < p; ++k) {
        string str;
        for (int i = 0; i < n; ++i) {
            scanf("%s", line);
            str += line;
        }
        s.push_back(str);
    }

    if (p==2 || p==3) {
        printf("%d\n", p-1);
        return;
    }

    if (p == 4) case4();
    else if (p == 5) case5();
    else case6();
    return;
}

int main() {
    solve1();
    return 0;
}