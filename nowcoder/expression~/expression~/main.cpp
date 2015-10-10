#include <iostream>
#include <string>
using namespace std;

class Expression {
public:
    int countWays(string exp, int len, int ret) {
		for (int i = 0; i < len; ++i) {
            if (i&1==0 && (exp[i]!='0'&&exp[i]!='1')) return 0;
            else if (i&1==1 && (exp[i]!='&'&&exp[i]!='|'&&exp[i]!='^')) return 0;
        }

    }
};

int main()
{
	Expression sol;
	cout << sol.countWays("1^0|0|1", 7, 0) << endl;
	return 0;
}