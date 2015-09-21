#include <cstdio>
using namespace std;

int m, n;
const int maxn = 50010;
int id[maxn], relation[maxn];

void init_set()
{
	for(int i = 0; i<n; i++)
		id[i] = i;
	return;
}

bool rel(int a, int b, int type){
		if(a >= n || b >= n)
			return false;
		
		if(type == 1 && a == b)
			return false;
		
		int aRel = 0, bRel = 0, aRoot = a, bRoot = b;
		while(aRoot != id[aRoot]){
			aRel += relation[aRoot];
			aRoot = id[aRoot];
		}
		id[a] = aRoot;
		aRel = aRel % 3;
		relation[a] = aRel;
		
		while(bRoot != id[bRoot]){
			bRel += relation[bRoot];
			bRoot = id[bRoot];
		}
		id[b] = bRoot;
		bRel = bRel % 3;
		relation[b] = bRel;
		
		if(aRoot == bRoot)
			return (aRel+3-bRel) % 3 == type;
		
		int newRel = (bRel+3-aRel+type) % 3;
		id[aRoot] = bRoot;
		relation[aRoot] = newRel;
		
		return true;
	}

int main() {
		
	scanf("%d %d", &n, &m);

	int fakeCnt = 0;
	init_set();
	for(int i = 0; i< m; i++){
		int type, x, y;
		scanf("%d %d %d", &type, &x, &y);
		if(! rel(x-1, y-1, type-1)){
			fakeCnt ++;
		}
	}
	printf("%d\n", fakeCnt);
		
	return 0;
}
