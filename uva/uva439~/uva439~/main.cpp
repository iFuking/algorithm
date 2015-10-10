#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 9;
typedef struct {
	int x;
	int y;
	int step;  // at location (i, j) takes 'step' steps
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
	queue<Point> q;
	q.push(start_p);
	memset(visit, 0, sizeof(visit));
	while (!q.empty())
	{
		Point point = q.front(); q.pop();
		for (int i = 0; i < 8; i++)
		{
			Point tmp;
			tmp.x = point.x + dir[i][0];
			tmp.y = point.y + dir[i][1];
			if (inside(tmp.x,tmp.y) && !visit[tmp.x][tmp.y])
			{
				tmp.step = point.step + 1;
				if (tmp.x==end_p.x && tmp.y==end_p.y) 
				{ 
					cout << "To get from " << start_point << " to " \
						<< end_point << " takes " << tmp.step << " knight moves." << endl;
					return;
				}
				q.push(tmp);
				visit[tmp.x][tmp.y] = true;
			}
		}
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