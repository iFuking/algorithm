#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int ans = 0;
    for (int i = 0; i < A.size(); ++i) {
        ans ^= A[i];
    }
    return ans;
}

int main() {
    int a[] = {9, 3, 9, 3, 9, 7, 9};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    
    while (true) {
        // int n; cin >> n;
        cout << solution(v) << endl;
    }
    return 0;
}