#include <iostream>
using namespace std;

bool table[6][6] = {0};
int pieces_in_row[6] = {0};
int pieces_in_col[6] = {0};

void dfs(int s, int &result)
{
    if (s == 36) {
        for (int i = 0; i < 6; i++) {
            if (pieces_in_row[i] != 3 || pieces_in_col[i] != 3)
                return;
        }
        result++;
        return;
    }
    for (int i = 0; i < s/6; i++) {
        if (pieces_in_row[i] != 3)
            return;
    }
    if (!table[s/6][s%6] && pieces_in_row[s/6] < 3 && pieces_in_col[s%6] < 3) {
        pieces_in_row[s/6]++;
        pieces_in_col[s%6]++;
        dfs(s+1, result);
        pieces_in_row[s/6]--;
        pieces_in_col[s%6]--;
        dfs(s+1, result);
    } else {
        dfs(s+1, result);
    }
}

int main()
{
    freopen("/Users/noosc/Desktop/input.txt","r",stdin);
    freopen("/Users/noosc/Desktop/output.txt","w",stdout);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            char c;
            cin >> c;
            if (c == 'o') {
                table[i][j] = true;
                pieces_in_row[i]++;
                pieces_in_col[j]++;
            } else {
                table[i][j] = false;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 6; i++) {
        if (pieces_in_row[i] > 3 || pieces_in_col[i] > 3)
        {
            cout << result << endl;
            return 0;
        }
    }
    dfs(0, result);
    cout << result << endl;
    return 0;
}