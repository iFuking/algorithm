#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class GrayCode {
public:
    vector<string> getGray(int n) {
    	
    }
};

int main() {
	GrayCode gc;
	int n;
	while (scanf("%d", &n)) {
		vector<string> v = gc.getGray(n);
		for (int i = 0; i < v.size(); ++i) {
			printf("%s\n", v[i].c_str());
		}
	}
	return 0;
}