#include <iostream>
#include <cstdio>
using namespace std;

typedef struct {
    int x, y;
}Point;
Point p[3], pp;

int dist(const Point &p1, const Point &p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

void solve() {
    int r;
    cin >> r;
    for (int i = 0; i < 3; ++i) cin >> p[i].x >> p[i].y;
    cin >> pp.x >> pp.y;

    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        if (dist(p[i], pp) <= r*r) ++cnt;
    }
    // cout << cnt << "x" << endl;
    printf("%dx\n", cnt);
    return;
}

int main()
{
    solve();
    return 0;
}
