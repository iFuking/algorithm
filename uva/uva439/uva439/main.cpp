/*
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
*/
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 9;
typedef struct {
	int x;
	int y;
}Point;  // struct Point
int dir[][2] = {
	{1, 2}, {2, 1}, {2, -1}, {1, -2}, 
	{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};  // eight different directions
string start_point, end_point;  // input
Point start_p, end_p;  // turn input into coordinate
bool visit[maxn][maxn];

void init()  // turn input into coordinate
{
	start_p.x = start_point[0]-'a'+1;
	start_p.y = start_point[1]-'0';
	end_p.x = end_point[0]-'a'+1;
	end_p.y = end_point[1]-'0';
	return;
}

bool inside(int x, int y)
{
	if (x>=1 && x<=8 && y>=1 && y<=8) return true;
	return false;
}

void bfs()
{
	queue<Point> q; int step = 0;
	q.push(start_p);
	int head = 0, tail = 1;
	memset(visit, 0, sizeof(visit));
	while (!q.empty())
	{
		int tmptail = tail; step++;
		while (head < tail)  // every step/deep contains tail-head points
		{
			Point point = q.front(); q.pop();
			for (int i = 0; i < 8; i++)
			{
				Point tmp;
				tmp.x = point.x + dir[i][0];
				tmp.y = point.y + dir[i][1];
				// avoid visit the same point using visit[x][y]
				if (inside(tmp.x, tmp.y) && !visit[tmp.x][tmp.y])
				{
					tmptail++;
					if (tmp.x==end_p.x && tmp.y==end_p.y) 
					{ 
						cout << "To get from " << start_point << " to " \
							<< end_point << " takes " << step << " knight moves." << endl;
						return;
					}
					q.push(tmp);
					visit[tmp.x][tmp.y] = true;
				}
			}
			head++;
		}
		head = tail; tail = tmptail;
	}
	return;
}

int main()
{
	while (cin >> start_point >> end_point)
	{
		if (start_point == end_point) 
		{
			cout << "To get from " << start_point << " to " \
				<< end_point << " takes 0 knight moves." << endl;
			continue;
		}
		init();
		bfs();
	}
	return 0;
}