#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
long long eule[maxn];
int p[maxn][15];
int num[maxn];

class GcdAndPhi {
public:
	void init()
	{	
		int i, j;
		eule[1] = 1;	
		for(i = 2; i < maxn; i++)		
		{
			if(!eule[i])			
			{			
				for(j = i; j < maxn; j += i)				
				{				
					if(!eule[j])					
						eule[j] = j;				
					eule[j] = eule[j]*(i-1)/i;				
					p[j][num[j]++] = i;				
				}			
			}		
			eule[i] += eule[i-1];	
		}
	}

    vector<long long> calc(int T, vector<int> N) {

    }
};

int main()
{
	GcdAndPhi sol;
	sol.init();
	return 0;
}