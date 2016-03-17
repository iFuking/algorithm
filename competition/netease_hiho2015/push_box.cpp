#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int N, M, S;
vector<vector<int> > mp;
pair<int, int> man, box, des;
pair<int, int> man_mirror, box_mirror, des_mirror;

const int maxt = 1e4 +10;
int T;
char op[maxt];

bool reach_p() {
    for (int i = 0; i < T; ++i) {
        if (box.first==des.first &&
            box.second==des.second) {
            return true;
        }

        switch(op[i]) {
        case 'u':
            if (man.first != 0) {
                if (man.second==box.second && man.first-1==box.first) {
                    if (box.first!=0 && mp[box.first-1][box.second]!=4) {
                        mp[box.first-1][box.second] = 3;
                        mp[box.first][box.second] = 1;
                        mp[man.first][man.second] = 0;

                        --box.first;
                        --man.first;
                    }
                } else {
                    if (mp[man.first-1][man.second] != 4) {
                        mp[man.first-1][man.second] = 1;
                        mp[man.first][man.second] = 0;

                        --man.first;
                    }
                }
            }
            break;
        case 'd':
            if (man.first != M-1) {
                if (man.second==box.second && man.first+1==box.first) {
                    if (box.first!=M-1 && mp[box.first+1][box.second]!=4) {
                        mp[box.first+1][box.second] = 3;
                        mp[box.first][box.second] = 1;
                        mp[man.first][man.second] = 0;

                        ++box.first;
                        ++man.first;
                    }
                } else {
                    if (mp[man.first+1][man.second] != 4) {
                        mp[man.first+1][man.second] = 1;
                        mp[man.first][man.second] = 0;

                        ++man.first;
                    }
                }
            }
            break;
        case 'l':
            if (man.second != 0) {
                if (man.first==box.first && man.second-1==box.second) {
                    if (box.second!=0 && mp[box.first][box.second-1]!=4) {
                        mp[box.first][box.second-1] = 3;
                        mp[box.first][box.second] = 1;
                        mp[man.first][man.second] = 0;

                        --box.second;
                        --man.second;
                    }
                } else {
                    if (mp[man.first][man.second-1] != 4) {
                        mp[man.first][man.second-1] = 1;
                        mp[man.first][man.second] = 0;

                        --man.second;
                    }
                }
            }
            break;
        case 'r':
            if (man.second != N-1) {
                if (man.first==box.first && man.second+1==box.second) {
                    if (box.second!=N-1 && mp[box.first][box.second+1]!=4) {
                        mp[box.first][box.second+1] = 3;
                        mp[box.first][box.second] = 1;
                        mp[man.first][man.second] = 0;

                        ++box.second;
                        ++man.second;
                    }
                } else {
                    if (mp[man.first][man.second+1] != 4) {
                        mp[man.first][man.second+1] = 1;
                        mp[man.first][man.second] = 0;

                        ++man.second;
                    }
                }
            }
            break;
        default:
            break;
        }
    }
    return box.first==des.first & box.second==des.second;
}

void solve() {
    cin >> N >> M >> S;
    mp = vector<vector<int> >(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        getchar();
        for (int j = 0; j < N; ++j) {
            char ch; scanf("%c", &ch);
            mp[i][j] = ch-'0';

            if (mp[i][j] == 1) man = make_pair(i, j);
            else if (mp[i][j] == 2) des = make_pair(i, j);
            else if (mp[i][j] == 3) box = make_pair(i, j);
        }
    }
    man_mirror = man;
    box_mirror = box;
    des_mirror = des;

    while (S--) {
        scanf("%d %s", &T, op);

        if (reach_p()) printf("YES\n");
        else printf("NO\n");

        mp[man.first][man.second] = 0;
        mp[box.first][box.second] = 0;

        mp[man_mirror.first][man_mirror.second] = 1;
        mp[des_mirror.first][des_mirror.second] = 2;
        mp[box_mirror.first][box_mirror.second] = 3;

        man = man_mirror;
        box = box_mirror;
        des = des_mirror;
    }
    return;
}

int main() {
    solve();
    return 0;
}
